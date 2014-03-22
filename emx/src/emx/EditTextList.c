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
 * @file           EditTextList.c
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
#include "emx/Types.h"
#include "emx/Buttons.h"
#include "emx/Fonts.h"
#include "emx/Lcd.h"
#include "emx/Menu.h"

#include <stdlib.h>
#include <stdint.h>

uint8_t editTextList(ITextListIdx_t* aITextListIdx, uint8_t aY)
{
    // aY is the current yPos from were the edit was triggered
    /**
     * calculate the rectangle height on the display: 
     *    fontheight + 1 pix on top + 1 pix at bottom + 2*2 pix for the frame 
     */
    uint8_t fontHeight = FONTHEIGHT(EDITFONT);
    // re-use aY
    aY = (aY < LCDHEIGHT/2 -9? aY+11: aY - 25);

    uint8_t idx = aITextListIdx->m_idx;
    uint8_t count = aITextListIdx->m_entryCount;
    if (idx > count-1)
        idx = 0;
    const char* const* texts = (const char**) aITextListIdx->m_textP;
    // DBR("eIx", idx);
    // DBR("eCn", count);
    // DBR("eTx", texts);

    // we dont know what the longest text is, so we assume 100 pixels
    uint8_t textLength = 100;
    uint8_t x = (LCDWIDTH - textLength - 8) / 2; 
    drawEditFrame(x, aY, textLength, fontHeight);
    x += 4;
    aY += 4;

    uint8_t clearLength = textLength;
    uint8_t key = 0;

    while (1)
    {
        lcdBufFillRect(x, aY, clearLength, fontHeight+1, COL_WHITE);        
        // write current value
        
        char* str  = (char*) pgm_read_word(&texts[idx]);
        //        DBR("eSt", str);
        lcdBufPuts(AT_PGM, str, &EDITFONT, x, aY, COL_BLACK);

        uint8_t iconMask = BT_BACK|BT_ENTER;
        if (idx)
            iconMask |= BT_PLUS;

        if (idx < (count-1)) 
            iconMask |= BT_MINUS;

        setIcons(IT_EDIT, iconMask);
        lcdUpdate(1);

        key = pollButtons(BT_ALL, BF_ACCEL|BF_DELAY); 
        switch (key & 0xF0) // clean code
        {
            case BT_BACK: return BT_BACK;

                // the plus/minus keys are exchanged intentionally
            case BT_MINUS: 
                if (idx < (count-1))
                ++idx;
                break;
            case BT_PLUS: 
                if (idx)
                    --idx;
                break;
            case BT_ENTER: 
                aITextListIdx->m_idx = idx;
                return BT_ENTER;
        } // switch key
    } // while (1) 
    return key & 0xF0; // return pure key
} // editTextList
