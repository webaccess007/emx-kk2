/*---------------------------------------------------------------------------
  .                                 The "EMX"
  .                         Embedded Mutable eXecutive
  .                                 Framework
  .
  .                  Copyright (C) 2014 Edgar (emax) Hermanns 
  ---------------------------------------------------------------------------
  .
  . my $email = sprintf ("%s@%s.%s", "emax", "hermanns", "net");
  .
  . This program is free software: you can redistribute it and/or modify
  . it under the terms of the GNU General Public License as published by
  . the Free Software Foundation, either version 3 of the License, or
  . (at your option) any later version.
  .
  . This program is distributed in the hope that it will be useful,
  . but WITHOUT ANY WARRANTY; without even the implied warranty of
  . MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  . GNU General Public License for more details.
  .
  . You should have received a copy of the GNU General Public License
  . along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file           DisplayMenu.c
 * @brief          Embedded Mutable eXecutive component
 * @author         Edgar (emax) Hermanns
 * @date           20140227
 * @version        $Id$
 *
 * CHANGE LOG:
 * ##  who  yyyymmdd   bug#  description
 * --  ---  --------  -----  -------------------------------------------------
 *  1  ...  ........  .....  ........
 *  0  emx  20140227  -----  initial version
 */

#include "emx/Config.h"

#include "emx/Buttons.h"
#include "emx/EmxFont.h"
#include "emx/Fonts.h"
#include "emx/Hardware.h"
#include "emx/Lcd.h"
#include "emx/Menu.h"

#include <stdint.h>
#include <avr/pgmspace.h>

uint8_t displayMenu(const Menu_t* aMenu, uint8_t aButtonMask)
{
    /**
     * NOTE: this code shall not be physically integrated into main() as it is called
     *       recursively: menu->submenu->submenu ... <return<return
     */

    uint8_t startEntryNo = 0, selEntryNo = 0; // start with menuEntry    
    uint8_t rc = 0;
    MenuState_t ms = { .m_fontHeight = FONTHEIGHT(MENUFONT)+1,
                       .m_font = &MENUFONT, .m_selEntry = 0 };
    uint8_t menuLines  = (LCDHEIGHT-1)/ms.m_fontHeight - 1;
    //    uint8_t bottomY = LCDHEIGHT-ms.m_fontHeight;

    while(1)                                  // run until 'return'
    {
        uint8_t   line       = 0;             // display line
        uint8_t   curEntryNo = startEntryNo;  // currently processed menu entry 
        uint8_t    pType;
        ms.m_selPType        = 0;
        ms.m_curY            = 0;

        LCD_BUF_CLEAR();
        uint8_t y = 0;               

        const uint8_t entryCount = pgm_read_byte(&aMenu->m_entryCount);
        while ((line < menuLines) && curEntryNo < entryCount) // for all menu-entries
        {
            uint8_t fgColor = COL_BLACK;
            const MenuEntry_t* me =  &aMenu->m_entries[curEntryNo];
            pType = pgm_read_byte(&me->m_pType);
            TypeHandler_t th = (TypeHandler_t) pgm_read_word(&me->m_typeHandler);
            if (curEntryNo == selEntryNo)
            {
                ms.m_curY = y;                                  // backup
                ms.m_selEntry = me;                             // backup
                ms.m_selPType = pType;                          // backup
                if ((uint16_t) th < HND_SPECIAL)                // no handler
                {
                    lcdBufFillRect(0, y, LCDWIDTH, ms.m_fontHeight, COL_BLACK);
                    fgColor = COL_WHITE;
                }
            }                                                 // curEntryNo == selEntryNo

            uint8_t pixels = lcdBufPuts(AT_PGM, (const char*) pgm_read_word(&me->m_text), &MENUFONT, 
                                        0, y, fgColor);
            if ((uint16_t) th > HND_SPECIAL)                 // something to display on the right column
            {
                // display the value
                ms.m_curX = LCDWIDTH/2; // assumed first tab
                while (ms.m_curX < pixels)
                    ms.m_curX += 10;    // next tab
                
                // write the colon
                lcdBufPutc(':', &MENUFONT, ms.m_curX, y, fgColor);
                if (curEntryNo == selEntryNo)
                    fgColor = COL_WHITE;
                PtrUnion_t* unionAdr = (PtrUnion_t*) pgm_read_word(&me->m_ptr);                
                th(HT_DISPLAY, pType, unionAdr, y, fgColor);
            }

            y += ms.m_fontHeight;
            ++curEntryNo;                                     // count current position
            ++line;                                           // increase display line
            ++me;                                             // point to next menuEntry
        } // while me && y < lines
        
        uint8_t iconMask = aButtonMask;

        iconMask = aButtonMask;
        if (selEntryNo == 0)
            iconMask ^= BT_UP;                                // nothing above
        if (selEntryNo == (entryCount-1))                     // nothing below
            iconMask ^= BT_DOWN;
        if (ISREADONLY(ms.m_selPType))
            iconMask ^= BT_ENTER;                             // nothing to do

        setIcons(IT_MENU, iconMask);

        lcdUpdate(1);
        void* address;
        switch (pollButtons(BT_ALL, 1))
        {
            default: break;
            case BT_BACK:
                return rc;
                
            case BT_DOWN:
                if (selEntryNo < (entryCount -1))
                    ++selEntryNo;  
                break;

            case BT_UP:
                if (selEntryNo)
                    --selEntryNo;
                break;

            case BT_ENTER:
                address = (void*) pgm_read_word(&ms.m_selEntry->m_ptr.m_voidAdr);
                TypeHandler_t th = (TypeHandler_t) pgm_read_word(&ms.m_selEntry->m_typeHandler);

                if (ms.m_selPType == 0)
                {
                    if (ISVOID((uint16_t) th))
                        break;

                    // if (ISEXIT((uint16_t) th))
                    //     return rc | MR_EXIT;
                        
                    if (ISMENUHND((uint16_t) th))
                        rc = displayMenu((Menu_t*) address, 0xF0);
                    else if (ISFUNCHND((uint16_t) th))
                    {
                        MenuFunctor_t funcPtr = (MenuFunctor_t) address;
                        do
                            rc = funcPtr(&ms);
                        while ((rc & 0xC0) == MR_REPEAT);
                    }
                    break;
                } // if pType == 0
                
                if (ISREADONLY(ms.m_selPType))
                    break;
                
                if (th)
                {
                    PtrUnion_t* unionAdr = (PtrUnion_t*) pgm_read_word(&ms.m_selEntry->m_ptr);
                    th(HT_EDIT, ms.m_selPType, unionAdr, ms.m_curY, COL_WHITE); // COL_BLACK);
                }
                break; // end BT_ENTER
        } // switch pollButtons(..)
        
        if (rc & MR_EXIT)
            break;

        if(startEntryNo > selEntryNo) // selected entry is smaller than startEntryNo: reduce startEntryNo
            --startEntryNo;
        else if (selEntryNo >= (startEntryNo + menuLines))  // sel.m_entry>bottom-entry: ++startEntryNo
            ++startEntryNo;
    } // while 1    
    return rc; 
} // DisplayMenu

