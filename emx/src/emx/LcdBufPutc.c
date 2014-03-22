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
 * @file           LcdBufPutc.c
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


uint8_t lcdBufPutc(char c, const EmxFont_t* aFont, uint8_t x, uint8_t y, uint8_t aColor)
{   
    // BEWARE: 'aFont' must point to PROGMEM
    /* 
       NOTE: aColor reads 0b01234567  where bit
       .                    0         if on, says: only read width in pixels and return
       .                     1        if on, says: inverse the pixels
       .                      23      are still unused
       .                        4567  define the color. ST7565 only knows color '1' or '0'
     */


    uint8_t startCh             = pgm_read_byte(&aFont->startCh);       // code of first character in font

    if (c < startCh || c > pgm_read_byte(&aFont->endCh))
        return 0;

    uint8_t idx                = (c-startCh);
    uint8_t width              = getCharWidth(aFont, idx);
    uint8_t extraWidth;
    uint8_t att = getAttribs(aFont);
    if (att & FT_EXTRAWS)
        extraWidth = 1;
    else
        extraWidth = 0;
    
    if (aColor & LA_CHARWIDTHONLY)
        return width + extraWidth;
    
    uint8_t  bytesToRead         = getCharBytes(aFont, idx);
    uint16_t offset              = getCharOffset(aFont, idx);
    uint16_t curPix              = getCharFirstPix(aFont, idx);
    const uint8_t* fontPtr       = (uint8_t*) pgm_read_word(&aFont->firstChar);
    fontPtr                     +=  offset;

    uint8_t reverse = aColor & LA_REVERSE;
    aColor ^= LA_REVERSE;

    if (reverse)
    {
        lcdBufFillRect(x, y, width, FONTHEIGHT((*aFont)), aColor);
        aColor = !aColor;
    }

    while(bytesToRead)
    {
        uint8_t data = pgm_read_byte(fontPtr);
        // if (reverse)
        //     data = ~data;
        for (uint8_t bit=0x80; bit; bit >>= 1)
        {
            if (data & bit)
            {
                uint8_t px = x + (curPix%width);
                uint8_t py = y + (curPix/width);
                lcdBufSetPixel(px, py, aColor & 0x0F);
            }
            ++curPix;
        }
        --bytesToRead;
        ++fontPtr;                    // now pointing to next data byte
    } // while bytesToRead
    // enable lcd-update timer

    return width + extraWidth;
} // lcdBufPutc(char c, const EmxFont_t* aFont, uint8_t x, uint8_t y)
