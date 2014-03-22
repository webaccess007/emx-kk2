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
 * @file           EmxFont.h
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
#ifndef EMXFONT_H
#define EMXFONT_H

#include <stdint.h>

typedef enum  { 
    FT_FIXED = 0b00000001,
    FT_EXTRAWS = 0b10000000
} FontType_t;

typedef struct{ 
    const uint8_t  attribs;
    const uint8_t  height;
    const uint8_t  startCh;
    const uint8_t  endCh;
    const uint8_t  count;
    union {
        const uint8_t wbBits;
        const uint8_t fixedWidth;
    } wb;
    const uint8_t  foBits;
    const uint8_t* firstPixIdx;
    const uint8_t* bytesIdx;
    const uint8_t* offsetIdx;
    const uint8_t* firstChar;
    const uint8_t code[];
} EmxFont_t;

// height of the bitmap
#define        FONTHEIGHT(aFontPtr) (pgm_read_byte(&(aFontPtr.height)) + 1)

//uint8_t        getFontHeight(const EmxFont_t* aFont);
uint8_t        getAttribs(const EmxFont_t* aFont);
uint8_t        getCharBytes(const EmxFont_t* aFont, uint8_t aIdx);
uint8_t        getCharWidth(const EmxFont_t* aFont, uint8_t aIdx);
uint16_t       getCharOffset(const EmxFont_t* aFont, uint8_t aIdx);
uint16_t       getCharFirstPix(const EmxFont_t* aFont, uint8_t aIdx);


#endif
