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
 * @file           LcdBufWriteEmxLogo.c
 * @brief          Embedded Mutable eXecutive component
 * @author         Edgar (emax) Hermanns
 * @date           20140315
 * @version        $Id$
 *
 * CHANGE LOG:
 * ##  who  yyyymmdd   bug#  description
 * --  ---  --------  -----  -------------------------------------------------
 *  1  ...  ........  .....  ........
 *  0  emx  20140315  -----  initial version
 */
#include "emx/Config.h"
#include "emx/Types.h"
#include "emx/Lcd.h"

#include <avr/pgmspace.h>

#include <stdint.h>

const unsigned char LogoVType[] PROGMEM = { 
        // character width: 2 bits per entry, 36 entries
        // 3, 2, 2, 3, 3, 3, 3, 3, 3, 3, 2, 3, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 
        // 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 
        // 1110101111111111111110111010101010101110101010101010101010101010
             0xEB,   0xFF,   0xFB,   0xAA,   0xAE,   0xAA,   0xAA,   0xAA,
        // 00000000
             0x00,

}; // VType
const unsigned char LogoVX[] PROGMEM = { 
        // character width: 6 bits per entry, 36 entries
        // 0, 32, 55, 0, 8, 33, 28, 8, 47, 10, 37, 0, 55, 8, 47, 28, 8, 33, 
        // 0, 32, 18, 40, 17, 39, 16, 38, 16, 38, 39, 17, 40, 18, 56, 9, 48, 
        // 56, 
        // 0000001000001101110000000010001000010111000010001011110010101001
             0x02,   0x0D,   0xC0,   0x22,   0x17,   0x08,   0xBC,   0xA9,
        // 0100000011011100100010111101110000100010000100000010000001001010
             0x40,   0xDC,   0x8B,   0xDC,   0x22,   0x10,   0x20,   0x4A,
        // 1000010001100111010000100110010000100110100111010001101000010010
             0x84,   0x67,   0x42,   0x64,   0x26,   0x9D,   0x1A,   0x12,
        // 111000001001110000111000
             0xE0,   0x9C,   0x38,

}; // VX

const unsigned char LogoVY[] PROGMEM = { 
        // character width: 6 bits per entry, 36 entries
        // 0, 0, 4, 5, 8, 8, 10, 13, 13, 28, 28, 32, 32, 33, 33, 37, 47, 47, 
        // 55, 55, 16, 16, 17, 17, 18, 18, 41, 41, 42, 42, 43, 43, 4, 47, 47, 
        // 55, 
        // 0000000000000001000001010010000010000010100011010011010111000111
             0x00,   0x01,   0x05,   0x20,   0x82,   0x8D,   0x35,   0xC7,
        // 0010000010000010000110000110010110111110111111011111011101000001
             0x20,   0x82,   0x18,   0x65,   0xBE,   0xFD,   0xF7,   0x41,
        // 0000010001010001010010010010101001101001101010101010101011101011
             0x04,   0x51,   0x49,   0x2A,   0x69,   0xAA,   0xAA,   0xEB,
        // 000100101111101111110111
             0x12,   0xFB,   0xF7,

}; // LogoVY

const unsigned char LogoVXl[] PROGMEM = { 
        // character width: 5 bits per entry, 36 entries
        // 28, 28, 5, 5, 19, 19, 4, 5, 5, 13, 13, 5, 5, 5, 5, 4, 19, 19, 28, 
        // 28, 2, 2, 4, 4, 6, 6, 6, 6, 4, 4, 2, 2, 3, 3, 3, 3, 
        // 1110011100001010010110011100110010000101001010110101101001010010
             0xE7,   0x0A,   0x59,   0xCC,   0x85,   0x2B,   0x5A,   0x52,
        // 1001010010100100100111001111100111000001000010001000010000110001
             0x94,   0xA4,   0x9C,   0xF9,   0xC1,   0x08,   0x84,   0x31,
        // 1000110001100010000100000100001000011000110001100011
             0x8C,   0x62,   0x10,   0x42,   0x18,   0xC6,   0x30,

}; // VXl
const unsigned char LogoVYl[] PROGMEM = { 
        // character width: 5 bits per entry, 36 entries
        // 5, 5, 24, 23, 5, 5, 13, 14, 14, 4, 4, 23, 24, 15, 15, 13, 5, 5, 5, 
        // 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
        // 0010100101110001011100101001010110101110011100010000100101111100
             0x29,   0x71,   0x72,   0x95,   0xAE,   0x71,   0x09,   0x7C,
        // 0011110111101101001010010100101001010000100001000010000100001000
             0x3D,   0xED,   0x29,   0x4A,   0x50,   0x84,   0x21,   0x08,
        // 0100001000010000100001000010000100001000010000100001
             0x42,   0x10,   0x84,   0x21,   0x08,   0x42,   0x10,

}; // LogoVYl

void lcdBufWriteEmxLogo(uint8_t aX, uint8_t aY, uint8_t aColor)
{
    //    uint16_t getBitCodedNumber(const unsigned char* bitCode, uint8_t idx, uint8_t bits);    
    for (uint8_t vec = 0; vec < 36; ++vec)
    {
        uint8_t type = getBitCodedNumber(LogoVType, vec, 2);
        uint8_t x    = aX + getBitCodedNumber(LogoVX, vec, 6);
        uint8_t y    = aY + getBitCodedNumber(LogoVY, vec, 6);
        uint8_t xl   = getBitCodedNumber(LogoVXl, vec, 5);
        uint8_t yl   = getBitCodedNumber(LogoVYl, vec, 5);
        uint8_t color = type >> 1;
        // if (!aColor)
        //     color = ~color & 0b00000001;
        uint8_t drawType = (type & 0b00000001);
        // DBR("t", type);
        // DBR("co", color);
        // DBR("x", x);
        // DBR("y", y);
        // DBR("xl", xl);
        // DBR("yl", yl);
        // DBR("dT", drawType);

        if (drawType == 0) // rect
            //            lcdBufFillRect(x, y, xl, yl, color);
            lcdBufDrawrect(x, y, xl-2, yl-2, color);
        else
            lcdBufFillRect(x, y, xl, yl, color);
    }

    // paint the 'X'
    uint8_t x = aX+16;
    uint8_t x2 = aX+37;
    for (uint8_t y = aY+19; y < aY+41; ++y)
    {
        lcdBufFillRect(x, y, 7, 1, aColor);
        lcdBufFillRect(x2, y, 7, 1,aColor);
        ++x;
        --x2;
    }
} // lcdBufWriteEmxLogo
