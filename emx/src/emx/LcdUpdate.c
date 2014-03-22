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
 * @file           LcdUpdate.c
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
#include "emx/Lcd.h"

#include <stdint.h>

void lcdUpdate(uint8_t aMode)
{
    uint8_t* buf = (aMode ? &LcdBuffer[0] : 0);
    for(int8_t p = 7; p >= 0; --p) 
    {
        // process 8 'pages' which are organized top-down and make 
        // the entire display, 8 bits downwards each
        lcdSend(LCD_COMMAND, LCMD_SET_COLUMN_LOWER | (0x0 & 0xf)); // Column 0
        lcdSend(LCD_COMMAND, LCMD_SET_COLUMN_UPPER | ((0x0 >> 4) & 0xf)); // Column 0
        lcdSend(LCD_COMMAND, LCMD_SET_PAGE | p); // Page 0 to 7
        
        for(uint8_t c = 0; c < LCDWIDTH; ++c)
        {
            if (aMode)
            {
                lcdSend(LCD_DATA, *buf);
                ++buf;
            }
            else
                lcdSend(LCD_DATA, 0x00); // clear
        }
    } // for p ... (pages)
} // lcdUpdate

