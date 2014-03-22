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
 * @file           LcdBufPuts.c
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
#include "emx/Lcd.h"

#include <stdint.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

// read from PROGMEM 
uint8_t lcdBufPuts(AdrType_t aAdrType, const char* s, 
                   const EmxFont_t* font, uint8_t x, uint8_t y, uint8_t aColor)
{
    // returns length of string in pixels
    uint8_t dx     = 0;                  //relativ xpos of character
    char ch;

    while ( (ch = (aAdrType == AT_RAM ? *s : pgm_read_byte(s))) != 0)
    {
        if (ch == '\n')
        {
            dx = 0;
            //            y += getFontHeight(font);
            y += FONTHEIGHT( (*font) );
        }
        else
            dx += lcdBufPutc(ch, font, x + dx, y, aColor);
        ++s;
    } // while (*s)
    return dx;
} // lcdBufPuts

