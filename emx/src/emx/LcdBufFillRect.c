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
 * @file           LcdBufFillRect.c
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

void lcdBufFillRect(uint8_t aX, uint8_t aY, uint8_t aWidth, uint8_t aHeight, uint8_t aColor)
{
    aColor &= 0x0F;     // only aColor & 0x0F is used: 16 colors
    uint8_t y = aY;
    while(aHeight && (y < LCDHEIGHT)) 
    {
        uint8_t x = aX;
        uint8_t dx = aWidth;
        while (dx && (x < LCDWIDTH))
        {
            lcdBufSetPixel(x, y, aColor);
            ++x;
            --dx;
        }
        ++y;
        --aHeight;        
    } // while 
} // lcdBufFillRect
