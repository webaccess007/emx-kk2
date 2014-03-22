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
 * @file           Debug.c
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

#include "emx/Debug.h"
#include "emx/Fonts.h"
#include "emx/Lcd.h"
#include "emx/Buttons.h"

#include <stdint.h>
#include <avr/pgmspace.h>

const char HexTab[] PROGMEM = "0123456789ABCDEF";

uint8_t DebugHex(AdrType_t aAdrType, const char* aLbl, const void* aPtr, uint8_t aLen)
{
    // clear the debug area
    lcdBufFillRect(0, LCDHEIGHT/2, LCDWIDTH, LCDHEIGHT/2, COL_WHITE);   

    // Y = (bottom - 3 lines), each of which is fontheight + 1
    uint8_t y = LCDHEIGHT - (3*9);
    uint8_t x = 0;
   
    while (aLbl && *aLbl)
    {
        x += lcdBufPutc(*aLbl, &DBGFONT, x, y, COL_BLACK);
        if (x >= LCDWIDTH)
            break;
        ++aLbl;
    }

    x+= 5;
    if (x < LCDWIDTH)
    {
        uint8_t valL = ((uint16_t) aPtr >> 8);
        uint8_t valH = ((uint16_t) aPtr);
        char info[] = { aAdrType,' ',                
                        pgm_read_byte(HexTab+(valH>>4)), 
                        pgm_read_byte(HexTab+(valH&0x0F)), ' ',
                        pgm_read_byte(HexTab+(valL>>4)), 
                        pgm_read_byte(HexTab+(valL&0x0F)), ' ', ' ',
                        'L', ' ',
                        pgm_read_byte(HexTab+(aLen >> 4)),
                        pgm_read_byte(HexTab+(aLen & 0x0F)) };

        for (uint8_t i = 0; i < sizeof(info); ++i)
            x += lcdBufPutc(info[i], &DBGFONT, x, y, COL_BLACK); // add some extra whitespace
    } // x < LCDWIDTH

    y += 9;
    x=0;   
    uint8_t key = 0;
    while (aLen)
    {        
        uint8_t val = (aAdrType == AT_RAM ? *(uint8_t*)aPtr : pgm_read_byte(aPtr));
        x += lcdBufPutc((char) pgm_read_byte(HexTab+(val>>4)), &DBGFONT, x, y, COL_BLACK);
        x += lcdBufPutc((char) pgm_read_byte(HexTab+(val & 0x0F)), &DBGFONT, x, y, COL_BLACK) + 2;  // add some extra 'whitespace'

        if (x > (LCDWIDTH-16))     // keep 16 pixels for next hexPair
        {
            x = 0;
            y += 9;// next line
        }
        if (y >= (LCDHEIGHT - 8) || aLen == 1) // end of screen or last character written
        {
            lcdUpdate(1);
            key = pollButtons(0xFF, 1);
            y = LCDHEIGHT - (4*9);
        }
        --aLen;
        ++aPtr;
    }
    //    lcdBufFillRect(0, LCDHEIGHT - (4*9), 0);
    return key;
} // Debug 


