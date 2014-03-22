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
 * @file           FontVerdana11.c
 * @brief          Embedded Mutable eXecutive component
 * @author         Edgar (emax) Hermanns
 * @date           20140309
 * @version        $Id$
 *
 * CHANGE LOG:
 * ##  who  yyyymmdd   bug#  description
 * --  ---  --------  -----  -------------------------------------------------
 *  1  ...  ........  .....  ........
 *  0  emx  20140309  -----  initial version
 */
#include "emx/EmxFont.h"

#include <avr/pgmspace.h>

#include <stdint.h>


const EmxFont_t Verdana11 PROGMEM = { 
     // Size: Header(12/0x000C)+Index(264/0x0108)+Maps(393/0x0189)=669/0x029D
    .attribs     = 0x80,    // bit7 set: add extra whitespace upon rendering, bit0 set: fixed font
#ifdef MAPCOUNT
#error MAPCOUNT already defined before
#endif
#define MAPCOUNT 91
    .height      = 0x0A,  // add 1 for real height (0..A == 11)
    .startCh     = 0x20,  // [ ]
    .endCh       = 0x7A,  // [z]
    .count       = MAPCOUNT,
    .wb          = {
        .wbBits      = 0x44,  // 4 bits width, 4 bits byte count
     },
    .foBits      = 0x69,  // 6 bits firstPixel, 9 bits offset
                                                                  // width starts at &code
    .bytesIdx    = &(Verdana11.code[(4*MAPCOUNT+7)/8]),                  // start of bytesIndex
    .firstPixIdx = &(Verdana11.code[(4*MAPCOUNT+7)/8 + (4*MAPCOUNT+7)/8]),  // start of firstPixelIndex

    .offsetIdx   = &(Verdana11.code[(4*MAPCOUNT+7)/8 + (4*MAPCOUNT+7)/8 +   // start of offsetIndex
                                   (6*MAPCOUNT+7)/8]), 
    .firstChar   = &(Verdana11.code[(4*MAPCOUNT+7)/8 + (4*MAPCOUNT+7)/8 +   // start of bit maps
                                   (6*MAPCOUNT+7)/8 + (9*MAPCOUNT+7)/8]), 
#undef MAPCOUNT
    .code      = { 
        // Index of 264/0x108 bytes follows, organisation is bitcoded:

        // character width: 4 bits per entry
        // 1, 1, 0, 0, 0, 10, 0, 0, 3, 3, 0, 0, 2, 3, 1, 0, 5, 5, 5, 5, 6, 5, 
        // 5, 5, 5, 5, 1, 0, 0, 0, 0, 4, 0, 6, 6, 7, 7, 5, 5, 7, 6, 3, 4, 6, 
        // 5, 7, 6, 7, 5, 7, 6, 6, 7, 6, 6, 9, 6, 7, 6, 0, 12, 0, 9, 9, 12, 
        // 5, 5, 5, 5, 5, 4, 5, 5, 1, 3, 5, 1, 9, 5, 5, 5, 5, 4, 4, 4, 5, 5, 
        // 7, 5, 5, 4, 
        // 0001000100000000000010100000000000110011000000000010001100010000
             0x11,   0x00,   0x0A,   0x00,   0x33,   0x00,   0x23,   0x10,
        // 0101010101010101011001010101010101010101000100000000000000000100
             0x55,   0x55,   0x65,   0x55,   0x55,   0x10,   0x00,   0x04,
        // 0000011001100111011101010101011101100011010001100101011101100111
             0x06,   0x67,   0x75,   0x57,   0x63,   0x46,   0x57,   0x67,
        // 0101011101100110011101100110100101100111011000001100000010011001
             0x57,   0x66,   0x76,   0x69,   0x67,   0x60,   0xC0,   0x99,
        // 1100010101010101010101010100010101010001001101010001100101010101
             0xC5,   0x55,   0x55,   0x45,   0x51,   0x35,   0x19,   0x55,
        // 01010101010001000100010101010111010101010100
             0x55,   0x44,   0x45,   0x57,   0x55,   0x40,

        // bytes: 4 bits per entry
        // 1, 1, 1, 1, 1, 10, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 5, 5, 5, 5, 6, 5, 
        // 5, 5, 5, 5, 1, 1, 1, 1, 1, 4, 1, 6, 6, 7, 7, 5, 5, 7, 6, 3, 4, 6, 
        // 5, 7, 6, 7, 5, 9, 6, 6, 7, 6, 6, 9, 6, 7, 6, 1, 10, 1, 10, 10, 10, 
        // 4, 6, 4, 6, 4, 4, 5, 6, 2, 4, 6, 2, 7, 4, 4, 5, 5, 3, 3, 4, 4, 4, 
        // 6, 4, 5, 3, 
        // 0001000100010001000110100001000101000100000100010001000100010001
             0x11,   0x11,   0x1A,   0x11,   0x44,   0x11,   0x11,   0x11,
        // 0101010101010101011001010101010101010101000100010001000100010100
             0x55,   0x55,   0x65,   0x55,   0x55,   0x11,   0x11,   0x14,
        // 0001011001100111011101010101011101100011010001100101011101100111
             0x16,   0x67,   0x75,   0x57,   0x63,   0x46,   0x57,   0x67,
        // 0101100101100110011101100110100101100111011000011010000110101010
             0x59,   0x66,   0x76,   0x69,   0x67,   0x61,   0xA1,   0xAA,
        // 1010010001100100011001000100010101100010010001100010011101000100
             0xA4,   0x64,   0x64,   0x45,   0x62,   0x46,   0x27,   0x44,
        // 01010101001100110100010001000110010001010011
             0x55,   0x33,   0x44,   0x46,   0x45,   0x30,

        // first pixel: 6 bits per entry
        // 0, 1, 0, 0, 0, 11, 0, 0, 2, 0, 0, 0, 15, 15, 7, 0, 6, 7, 6, 6, 10, 
        // 5, 7, 5, 6, 6, 3, 0, 0, 0, 0, 4, 0, 8, 6, 9, 7, 5, 5, 9, 6, 3, 5, 
        // 6, 5, 7, 6, 9, 5, 9, 6, 7, 7, 6, 6, 9, 6, 7, 6, 0, 27, 0, 13, 12, 
        // 32, 16, 0, 16, 4, 16, 2, 16, 0, 0, 2, 0, 0, 27, 15, 16, 15, 16, 12, 
        // 13, 5, 15, 15, 21, 15, 15, 12, 
        // 0000000000010000000000000000000010110000000000000000100000000000
             0x00,   0x10,   0x00,   0x00,   0xB0,   0x00,   0x08,   0x00,
        // 0000000000111100111100011100000000011000011100011000011000101000
             0x00,   0x3C,   0xF1,   0xC0,   0x18,   0x71,   0x86,   0x28,
        // 0101000111000101000110000110000011000000000000000000000000000100
             0x51,   0xC5,   0x18,   0x60,   0xC0,   0x00,   0x00,   0x04,
        // 0000000010000001100010010001110001010001010010010001100000110001
             0x00,   0x81,   0x89,   0x1C,   0x51,   0x49,   0x18,   0x31,
        // 0100011000010100011100011000100100010100100100011000011100011100
             0x46,   0x14,   0x71,   0x89,   0x14,   0x91,   0x87,   0x1C,
        // 0110000110001001000110000111000110000000011011000000001101001100
             0x61,   0x89,   0x18,   0x71,   0x80,   0x6C,   0x03,   0x4C,
        // 1000000100000000000100000001000100000000100100000000000000000000
             0x81,   0x00,   0x10,   0x11,   0x00,   0x90,   0x00,   0x00,
        // 1000000000000001101100111101000000111101000000110000110100010100
             0x80,   0x01,   0xB3,   0xD0,   0x3D,   0x03,   0x0D,   0x14,
        // 1111001111010101001111001111001100
             0xF3,   0xD5,   0x3C,   0xF3,   0x00,

        // offsets: 9 bits per entry
        // 0, 1, 2, 2, 2, 2, 12, 12, 12, 16, 20, 20, 20, 21, 22, 23, 23, 28, 
        // 33, 38, 43, 49, 54, 59, 64, 69, 74, 75, 75, 75, 75, 75, 79, 79, 85, 
        // 91, 98, 105, 110, 115, 122, 128, 131, 135, 141, 146, 153, 159, 166, 
        // 171, 180, 186, 192, 199, 205, 211, 220, 226, 233, 239, 239, 249, 
        // 249, 259, 269, 279, 283, 289, 293, 299, 303, 307, 312, 318, 320, 
        // 324, 330, 332, 339, 343, 347, 352, 357, 360, 363, 367, 371, 375, 
        // 381, 385, 390, 
        // 0000000000000000010000000100000000100000000100000000100000011000
             0x00,   0x00,   0x40,   0x40,   0x20,   0x10,   0x08,   0x18,
        // 0000110000000110000001000000001010000001010000001010000001010100
             0x0C,   0x06,   0x04,   0x02,   0x81,   0x40,   0xA0,   0x54,
        // 0010110000010111000010111000011100000100001000100110000101011000
             0x2C,   0x17,   0x0B,   0x87,   0x04,   0x22,   0x61,   0x58,
        // 1100010001101100001110110010000000010001010010010100010010110010
             0xC4,   0x6C,   0x3B,   0x20,   0x11,   0x49,   0x44,   0xB2,
        // 0101100100101100100101100100101100100111100100111100101010100101
             0x59,   0x2C,   0x96,   0x4B,   0x27,   0x93,   0xCA,   0xA5,
        // 1011001100010001101001001101110001110011001111010010000000010000
             0xB3,   0x11,   0xA4,   0xDC,   0x73,   0x3D,   0x20,   0x10,
        // 0110100001110100011010100100100100110010100111110101001100101010
             0x68,   0x74,   0x6A,   0x49,   0x32,   0x9F,   0x53,   0x2A,
        // 1101011010001011101001100000001100011101100110101101001101101110
             0xD6,   0x8B,   0xA6,   0x03,   0x1D,   0x9A,   0xD3,   0x6E,
        // 0011100010011101001011101111011101111011111001011111001100000011
             0x38,   0x9D,   0x2E,   0xF7,   0x7B,   0xE5,   0xF3,   0x03,
        // 1000011011000101111000110111001000011001001011001010111001011111
             0x86,   0xC5,   0xE3,   0x72,   0x19,   0x2C,   0xAE,   0x5F,
        // 0011001110011100010011111010100000010100010010100101010100110010
             0x33,   0x9C,   0x4F,   0xA8,   0x14,   0x4A,   0x55,   0x32,
        // 1010011101010111101011011101100000101100101101101000101101011101
             0xA7,   0x57,   0xAD,   0xD8,   0x2C,   0xB6,   0x8B,   0x5D,
        // 101111101110011101110111101111101110000001110000110
             0xBE,   0xE7,   0x77,   0xBE,   0xE0,   0x70,   0xC0,

        //  .   char[ ], hex[0x20], idx[0], width[1], first pixel[0], offset[0/0x00]
        //  .
        //  .
        //  .
        //  .
        //  .
        //  .
        //  .
        //  .
        //  .
        //  .
        0x00, 

        //  .   char[!], hex[0x21], idx[1], width[1], first pixel[1], offset[1/0x01]
        //  X
        //  X
        //  X
        //  X
        //  X
        //  X
        //  .
        //  X
        //  .
        //  .
        0xFD, 

        // skipped character '"' (0x22)
        // skipped character '#' (0x23)
        // skipped character '$' (0x24)

        //  ..........   char[%], hex[0x25], idx[5], width[10], first pixel[11], offset[2/0x02]
        //  .XX...X...
        //  X..X..X...
        //  X..X.X....
        //  .XX..X....
        //  ....X..XX.
        //  ....X.X..X
        //  ...X..X..X
        //  ...X...XX.
        //  ..........
        //  ..........
        0xC4, 0x49, 0x12, 0x83, 0x20, 0x13, 0x05, 0x22, 0x48, 0x8C, 

        // skipped character '&' (0x26)
        // skipped character ''' (0x27)

        //  ..X   char[(], hex[0x28], idx[8], width[3], first pixel[2], offset[12/0x0C]
        //  .X.
        //  .X.
        //  X..
        //  X..
        //  X..
        //  X..
        //  X..
        //  .X.
        //  .X.
        //  ..X
        0xA5, 0x24, 0x91, 0x22, 

        //  X..   char[)], hex[0x29], idx[9], width[3], first pixel[0], offset[16/0x10]
        //  .X.
        //  .X.
        //  ..X
        //  ..X
        //  ..X
        //  ..X
        //  ..X
        //  .X.
        //  .X.
        //  X..
        0x89, 0x12, 0x49, 0x4A, 

        // skipped character '*' (0x2A)
        // skipped character '+' (0x2B)

        //  ..   char[,], hex[0x2C], idx[12], width[2], first pixel[15], offset[20/0x14]
        //  ..
        //  ..
        //  ..
        //  ..
        //  ..
        //  ..
        //  .X
        //  .X
        //  .X
        //  X.
        0xAC, 

        //  ...   char[-], hex[0x2D], idx[13], width[3], first pixel[15], offset[21/0x15]
        //  ...
        //  ...
        //  ...
        //  ...
        //  XXX
        //  ...
        //  ...
        //  ...
        //  ...
        //  ...
        0xE0, 

        //  .   char[.], hex[0x2E], idx[14], width[1], first pixel[7], offset[22/0x16]
        //  .
        //  .
        //  .
        //  .
        //  .
        //  .
        //  X
        //  X
        //  .
        //  .
        0xC0, 

        // skipped character '/' (0x2F)

        //  .....   char[0], hex[0x30], idx[16], width[5], first pixel[6], offset[23/0x17]
        //  .XXX.
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  .XXX.
        //  .....
        //  .....
        0xE8, 0xC6, 0x31, 0x8C, 0x5C, 

        //  .....   char[1], hex[0x31], idx[17], width[5], first pixel[7], offset[28/0x1C]
        //  ..X..
        //  XXX..
        //  ..X..
        //  ..X..
        //  ..X..
        //  ..X..
        //  ..X..
        //  XXXXX
        //  .....
        //  .....
        0x9C, 0x21, 0x08, 0x42, 0x7C, 

        //  .....   char[2], hex[0x32], idx[18], width[5], first pixel[6], offset[33/0x21]
        //  .XXX.
        //  X...X
        //  ....X
        //  ...X.
        //  ..X..
        //  .X...
        //  X....
        //  XXXXX
        //  .....
        //  .....
        0xE8, 0x84, 0x44, 0x44, 0x3E, 

        //  .....   char[3], hex[0x33], idx[19], width[5], first pixel[6], offset[38/0x26]
        //  .XXX.
        //  X...X
        //  ....X
        //  ..XX.
        //  ....X
        //  ....X
        //  X...X
        //  .XXX.
        //  .....
        //  .....
        0xE8, 0x84, 0xC1, 0x0C, 0x5C, 

        //  ......   char[4], hex[0x34], idx[20], width[6], first pixel[10], offset[43/0x2B]
        //  ....X.
        //  ...XX.
        //  ..X.X.
        //  .X..X.
        //  X...X.
        //  XXXXXX
        //  ....X.
        //  ....X.
        //  ......
        //  ......
        0x86, 0x29, 0x28, 0xBF, 0x08, 0x20, 

        //  .....   char[5], hex[0x35], idx[21], width[5], first pixel[5], offset[49/0x31]
        //  XXXXX
        //  X....
        //  X....
        //  XXXX.
        //  ....X
        //  ....X
        //  X...X
        //  .XXX.
        //  .....
        //  .....
        0xFC, 0x21, 0xE0, 0x86, 0x2E, 

        //  .....   char[6], hex[0x36], idx[22], width[5], first pixel[7], offset[54/0x36]
        //  ..XX.
        //  .X...
        //  X....
        //  XXXX.
        //  X...X
        //  X...X
        //  X...X
        //  .XXX.
        //  .....
        //  .....
        0xC8, 0x87, 0xA3, 0x18, 0xB8, 

        //  .....   char[7], hex[0x37], idx[23], width[5], first pixel[5], offset[59/0x3B]
        //  XXXXX
        //  ....X
        //  ...X.
        //  ...X.
        //  ..X..
        //  ..X..
        //  .X...
        //  .X...
        //  .....
        //  .....
        0xF8, 0x44, 0x22, 0x11, 0x08, 

        //  .....   char[8], hex[0x38], idx[24], width[5], first pixel[6], offset[64/0x40]
        //  .XXX.
        //  X...X
        //  X...X
        //  .XXX.
        //  X...X
        //  X...X
        //  X...X
        //  .XXX.
        //  .....
        //  .....
        0xE8, 0xC5, 0xD1, 0x8C, 0x5C, 

        //  .....   char[9], hex[0x39], idx[25], width[5], first pixel[6], offset[69/0x45]
        //  .XXX.
        //  X...X
        //  X...X
        //  X...X
        //  .XXXX
        //  ....X
        //  ...X.
        //  .XX..
        //  .....
        //  .....
        0xE8, 0xC6, 0x2F, 0x08, 0x98, 

        //  .   char[:], hex[0x3A], idx[26], width[1], first pixel[3], offset[74/0x4A]
        //  .
        //  .
        //  X
        //  X
        //  .
        //  .
        //  X
        //  X
        //  .
        //  .
        0xCC, 

        // skipped character ';' (0x3B)
        // skipped character '<' (0x3C)
        // skipped character '=' (0x3D)
        // skipped character '>' (0x3E)

        //  ....   char[?], hex[0x3F], idx[31], width[4], first pixel[4], offset[75/0x4B]
        //  XXX.
        //  ...X
        //  ...X
        //  ..X.
        //  .X..
        //  .X..
        //  ....
        //  .X..
        //  ....
        //  ....
        0xE1, 0x12, 0x44, 0x04, 

        // skipped character '@' (0x40)

        //  ......   char[A], hex[0x41], idx[33], width[6], first pixel[8], offset[79/0x4F]
        //  ..XX..
        //  ..XX..
        //  .X..X.
        //  .X..X.
        //  .X..X.
        //  XXXXXX
        //  X....X
        //  X....X
        //  ......
        //  ......
        0xC3, 0x12, 0x49, 0x2F, 0xE1, 0x84, 

        //  ......   char[B], hex[0x42], idx[34], width[6], first pixel[6], offset[85/0x55]
        //  XXXX..
        //  X...X.
        //  X...X.
        //  XXXXX.
        //  X....X
        //  X....X
        //  X....X
        //  XXXXX.
        //  ......
        //  ......
        0xF2, 0x28, 0xBE, 0x86, 0x18, 0x7E, 

        //  .......   char[C], hex[0x43], idx[35], width[7], first pixel[9], offset[91/0x5B]
        //  ..XXXX.
        //  .X....X
        //  X......
        //  X......
        //  X......
        //  X......
        //  .X....X
        //  ..XXXX.
        //  .......
        //  .......
        0xF2, 0x18, 0x10, 0x20, 0x40, 0x42, 0x78, 

        //  .......   char[D], hex[0x44], idx[36], width[7], first pixel[7], offset[98/0x62]
        //  XXXXX..
        //  X....X.
        //  X.....X
        //  X.....X
        //  X.....X
        //  X.....X
        //  X....X.
        //  XXXXX..
        //  .......
        //  .......
        0xF9, 0x0A, 0x0C, 0x18, 0x30, 0x61, 0x7C, 

        //  .....   char[E], hex[0x45], idx[37], width[5], first pixel[5], offset[105/0x69]
        //  XXXXX
        //  X....
        //  X....
        //  XXXXX
        //  X....
        //  X....
        //  X....
        //  XXXXX
        //  .....
        //  .....
        0xFC, 0x21, 0xF8, 0x42, 0x1F, 

        //  .....   char[F], hex[0x46], idx[38], width[5], first pixel[5], offset[110/0x6E]
        //  XXXXX
        //  X....
        //  X....
        //  XXXX.
        //  X....
        //  X....
        //  X....
        //  X....
        //  .....
        //  .....
        0xFC, 0x21, 0xE8, 0x42, 0x10, 

        //  .......   char[G], hex[0x47], idx[39], width[7], first pixel[9], offset[115/0x73]
        //  ..XXXX.
        //  .X....X
        //  X......
        //  X......
        //  X...XXX
        //  X.....X
        //  .X....X
        //  ..XXXX.
        //  .......
        //  .......
        0xF2, 0x18, 0x10, 0x23, 0xC1, 0x42, 0x78, 

        //  ......   char[H], hex[0x48], idx[40], width[6], first pixel[6], offset[122/0x7A]
        //  X....X
        //  X....X
        //  X....X
        //  XXXXXX
        //  X....X
        //  X....X
        //  X....X
        //  X....X
        //  ......
        //  ......
        0x86, 0x18, 0x7F, 0x86, 0x18, 0x61, 

        //  ...   char[I], hex[0x49], idx[41], width[3], first pixel[3], offset[128/0x80]
        //  XXX
        //  .X.
        //  .X.
        //  .X.
        //  .X.
        //  .X.
        //  .X.
        //  XXX
        //  ...
        //  ...
        0xE9, 0x24, 0x97, 

        //  ....   char[J], hex[0x4A], idx[42], width[4], first pixel[5], offset[131/0x83]
        //  .XXX
        //  ...X
        //  ...X
        //  ...X
        //  ...X
        //  ...X
        //  ...X
        //  XXX.
        //  ....
        //  ....
        0xE2, 0x22, 0x22, 0x3C, 

        //  ......   char[K], hex[0x4B], idx[43], width[6], first pixel[6], offset[135/0x87]
        //  X....X
        //  X...X.
        //  X..X..
        //  X.X...
        //  XXX...
        //  X..X..
        //  X...X.
        //  X....X
        //  ......
        //  ......
        0x86, 0x29, 0x28, 0xE2, 0x48, 0xA1, 

        //  .....   char[L], hex[0x4C], idx[44], width[5], first pixel[5], offset[141/0x8D]
        //  X....
        //  X....
        //  X....
        //  X....
        //  X....
        //  X....
        //  X....
        //  XXXXX
        //  .....
        //  .....
        0x84, 0x21, 0x08, 0x42, 0x1F, 

        //  .......   char[M], hex[0x4D], idx[45], width[7], first pixel[7], offset[146/0x92]
        //  XX...XX
        //  XX...XX
        //  X.X.X.X
        //  X.X.X.X
        //  X..X..X
        //  X..X..X
        //  X.....X
        //  X.....X
        //  .......
        //  .......
        0xC7, 0x8E, 0xAD, 0x59, 0x32, 0x60, 0xC1, 

        //  ......   char[N], hex[0x4E], idx[46], width[6], first pixel[6], offset[153/0x99]
        //  XX...X
        //  XX...X
        //  X.X..X
        //  X.X..X
        //  X..X.X
        //  X..X.X
        //  X...XX
        //  X...XX
        //  ......
        //  ......
        0xC7, 0x1A, 0x69, 0x96, 0x58, 0xE3, 

        //  .......   char[O], hex[0x4F], idx[47], width[7], first pixel[9], offset[159/0x9F]
        //  ..XXX..
        //  .X...X.
        //  X.....X
        //  X.....X
        //  X.....X
        //  X.....X
        //  .X...X.
        //  ..XXX..
        //  .......
        //  .......
        0xE2, 0x28, 0x30, 0x60, 0xC1, 0x44, 0x70, 

        //  .....   char[P], hex[0x50], idx[48], width[5], first pixel[5], offset[166/0xA6]
        //  XXXX.
        //  X...X
        //  X...X
        //  X...X
        //  XXXX.
        //  X....
        //  X....
        //  X....
        //  .....
        //  .....
        0xF4, 0x63, 0x1F, 0x42, 0x10, 

        //  .......   char[Q], hex[0x51], idx[49], width[7], first pixel[9], offset[171/0xAB]
        //  ..XXX..
        //  .X...X.
        //  X.....X
        //  X.....X
        //  X.....X
        //  X.....X
        //  .X...X.
        //  ..XXX..
        //  ....X..
        //  .....XX
        0xE2, 0x28, 0x30, 0x60, 0xC1, 0x44, 0x70, 0x20, 0x30, 

        //  ......   char[R], hex[0x52], idx[50], width[6], first pixel[6], offset[180/0xB4]
        //  XXXX..
        //  X...X.
        //  X...X.
        //  X...X.
        //  XXXX..
        //  X..X..
        //  X...X.
        //  X....X
        //  ......
        //  ......
        0xF2, 0x28, 0xA2, 0xF2, 0x48, 0xA1, 

        //  ......   char[S], hex[0x53], idx[51], width[6], first pixel[7], offset[186/0xBA]
        //  .XXXX.
        //  X....X
        //  X.....
        //  .XX...
        //  ...XX.
        //  .....X
        //  X....X
        //  .XXXX.
        //  ......
        //  ......
        0xF4, 0x30, 0x30, 0x30, 0x30, 0xBC, 

        //  .......   char[T], hex[0x54], idx[52], width[7], first pixel[7], offset[192/0xC0]
        //  XXXXXXX
        //  ...X...
        //  ...X...
        //  ...X...
        //  ...X...
        //  ...X...
        //  ...X...
        //  ...X...
        //  .......
        //  .......
        0xFE, 0x20, 0x40, 0x81, 0x02, 0x04, 0x08, 

        //  ......   char[U], hex[0x55], idx[53], width[6], first pixel[6], offset[199/0xC7]
        //  X....X
        //  X....X
        //  X....X
        //  X....X
        //  X....X
        //  X....X
        //  X....X
        //  .XXXX.
        //  ......
        //  ......
        0x86, 0x18, 0x61, 0x86, 0x18, 0x5E, 

        //  ......   char[V], hex[0x56], idx[54], width[6], first pixel[6], offset[205/0xCD]
        //  X....X
        //  X....X
        //  X....X
        //  .X..X.
        //  .X..X.
        //  .X..X.
        //  ..XX..
        //  ..XX..
        //  ......
        //  ......
        0x86, 0x18, 0x52, 0x49, 0x23, 0x0C, 

        //  .........   char[W], hex[0x57], idx[55], width[9], first pixel[9], offset[211/0xD3]
        //  X...X...X
        //  X...X...X
        //  .X.X.X.X.
        //  .X.X.X.X.
        //  .X.X.X.X.
        //  .X.X.X.X.
        //  ..X...X..
        //  ..X...X..
        //  .........
        //  .........
        0x88, 0xC4, 0x55, 0x4A, 0xA5, 0x52, 0xA8, 0x88, 0x44, 

        //  ......   char[X], hex[0x58], idx[56], width[6], first pixel[6], offset[220/0xDC]
        //  X....X
        //  X....X
        //  .X..X.
        //  ..XX..
        //  ..XX..
        //  .X..X.
        //  X....X
        //  X....X
        //  ......
        //  ......
        0x86, 0x14, 0x8C, 0x31, 0x28, 0x61, 

        //  .......   char[Y], hex[0x59], idx[57], width[7], first pixel[7], offset[226/0xE2]
        //  X.....X
        //  .X...X.
        //  ..X.X..
        //  ...X...
        //  ...X...
        //  ...X...
        //  ...X...
        //  ...X...
        //  .......
        //  .......
        0x82, 0x88, 0xA0, 0x81, 0x02, 0x04, 0x08, 

        //  ......   char[Z], hex[0x5A], idx[58], width[6], first pixel[6], offset[233/0xE9]
        //  XXXXXX
        //  .....X
        //  ....X.
        //  ...X..
        //  ..X...
        //  .X....
        //  X.....
        //  XXXXXX
        //  ......
        //  ......
        0xFC, 0x10, 0x84, 0x21, 0x08, 0x3F, 

        // skipped character '[' (0x5B)

        //  ............   char[\], hex[0x5C], idx[60], width[12], first pixel[27], offset[239/0xEF]
        //  ............
        //  ...x........
        //  ..xx........
        //  .xxxxxxxxxxx
        //  xxxxxxxxxxxx
        //  .xxxxxxxxxxx
        //  ..xx........
        //  ...x........
        //  ............
        //  ............
        0x80, 0x18, 0x03, 0xFF, 0xFF, 0xFB, 0xFF, 0x98, 0x00, 0x80, 

        // skipped character ']' (0x5D)

        //  .........   char[^], hex[0x5E], idx[62], width[9], first pixel[13], offset[249/0xF9]
        //  ....x....
        //  ...xxx...
        //  ..xxxxx..
        //  .xxxxxxx.
        //  xxxxxxxxx
        //  ...xxx...
        //  ...xxx...
        //  ...xxx...
        //  ...xxx...
        //  .........
        0x80, 0xE0, 0xF8, 0xFE, 0xFF, 0x8E, 0x07, 0x03, 0x81, 0xC0, 

        //  .........   char[_], hex[0x5F], idx[63], width[9], first pixel[12], offset[259/0x103]
        //  ...xxx...
        //  ...xxx...
        //  ...xxx...
        //  ...xxx...
        //  xxxxxxxxx
        //  .xxxxxxx.
        //  ..xxxxx..
        //  ...xxx...
        //  ....x....
        //  .........
        0xE0, 0x70, 0x38, 0x1C, 0x7F, 0xDF, 0xC7, 0xC1, 0xC0, 0x40, 

        //  ............   char[`], hex[0x60], idx[64], width[12], first pixel[32], offset[269/0x10D]
        //  ............
        //  ........x...
        //  ........xx..
        //  xxxxxxxxxxx.
        //  xxxxxxxxxxxx
        //  xxxxxxxxxxx.
        //  ........xx..
        //  ........x...
        //  ............
        //  ............
        0x80, 0x0C, 0xFF, 0xEF, 0xFF, 0xFF, 0xE0, 0x0C, 0x00, 0x80, 

        //  .....   char[a], hex[0x61], idx[65], width[5], first pixel[16], offset[279/0x117]
        //  .....
        //  .....
        //  .XXX.
        //  ....X
        //  .XXXX
        //  X...X
        //  X...X
        //  .XXXX
        //  .....
        //  .....
        0xE0, 0xBE, 0x31, 0x78, 

        //  X....   char[b], hex[0x62], idx[66], width[5], first pixel[0], offset[283/0x11B]
        //  X....
        //  X....
        //  XXXX.
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  XXXX.
        //  .....
        //  .....
        0x84, 0x21, 0xE8, 0xC6, 0x31, 0xF0, 

        //  .....   char[c], hex[0x63], idx[67], width[5], first pixel[16], offset[289/0x121]
        //  .....
        //  .....
        //  .XXX.
        //  X...X
        //  X....
        //  X....
        //  X...X
        //  .XXX.
        //  .....
        //  .....
        0xE8, 0xC2, 0x11, 0x70, 

        //  ....X   char[d], hex[0x64], idx[68], width[5], first pixel[4], offset[293/0x125]
        //  ....X
        //  ....X
        //  .XXXX
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  .XXXX
        //  .....
        //  .....
        0x84, 0x2F, 0x8C, 0x63, 0x17, 0x80, 

        //  .....   char[e], hex[0x65], idx[69], width[5], first pixel[16], offset[299/0x12B]
        //  .....
        //  .....
        //  .XXX.
        //  X...X
        //  XXXXX
        //  X....
        //  X...X
        //  .XXX.
        //  .....
        //  .....
        0xE8, 0xFE, 0x11, 0x70, 

        //  ..XX   char[f], hex[0x66], idx[70], width[4], first pixel[2], offset[303/0x12F]
        //  .X..
        //  .X..
        //  XXXX
        //  .X..
        //  .X..
        //  .X..
        //  .X..
        //  .X..
        //  ....
        //  ....
        0xD1, 0x3D, 0x11, 0x11, 

        //  .....   char[g], hex[0x67], idx[71], width[5], first pixel[16], offset[307/0x133]
        //  .....
        //  .....
        //  .XXXX
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  .XXXX
        //  ....X
        //  .XXX.
        0xF8, 0xC6, 0x31, 0x78, 0x5C, 

        //  X....   char[h], hex[0x68], idx[72], width[5], first pixel[0], offset[312/0x138]
        //  X....
        //  X....
        //  XXXX.
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  .....
        //  .....
        0x84, 0x21, 0xE8, 0xC6, 0x31, 0x88, 

        //  X   char[i], hex[0x69], idx[73], width[1], first pixel[0], offset[318/0x13E]
        //  .
        //  .
        //  X
        //  X
        //  X
        //  X
        //  X
        //  X
        //  .
        //  .
        0x9F, 0x80, 

        //  ..X   char[j], hex[0x6A], idx[74], width[3], first pixel[2], offset[320/0x140]
        //  ...
        //  ...
        //  .XX
        //  ..X
        //  ..X
        //  ..X
        //  ..X
        //  ..X
        //  ..X
        //  XX.
        0x80, 0xC9, 0x24, 0x9C, 

        //  X....   char[k], hex[0x6B], idx[75], width[5], first pixel[0], offset[324/0x144]
        //  X....
        //  X....
        //  X...X
        //  X..X.
        //  X.X..
        //  XXX..
        //  X..X.
        //  X...X
        //  .....
        //  .....
        0x84, 0x21, 0x19, 0x53, 0x92, 0x88, 

        //  X   char[l], hex[0x6C], idx[76], width[1], first pixel[0], offset[330/0x14A]
        //  X
        //  X
        //  X
        //  X
        //  X
        //  X
        //  X
        //  X
        //  .
        //  .
        0xFF, 0x80, 

        //  .........   char[m], hex[0x6D], idx[77], width[9], first pixel[27], offset[332/0x14C]
        //  .........
        //  .........
        //  XXXX.XXX.
        //  X...X...X
        //  X...X...X
        //  X...X...X
        //  X...X...X
        //  X...X...X
        //  .........
        //  .........
        0xF7, 0x44, 0x62, 0x31, 0x18, 0x8C, 0x44, 

        //  .....   char[n], hex[0x6E], idx[78], width[5], first pixel[15], offset[339/0x153]
        //  .....
        //  .....
        //  XXXX.
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  .....
        //  .....
        0xF4, 0x63, 0x18, 0xC4, 

        //  .....   char[o], hex[0x6F], idx[79], width[5], first pixel[16], offset[343/0x157]
        //  .....
        //  .....
        //  .XXX.
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  .XXX.
        //  .....
        //  .....
        0xE8, 0xC6, 0x31, 0x70, 

        //  .....   char[p], hex[0x70], idx[80], width[5], first pixel[15], offset[347/0x15B]
        //  .....
        //  .....
        //  XXXX.
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  XXXX.
        //  X....
        //  X....
        0xF4, 0x63, 0x18, 0xFA, 0x10, 

        //  .....   char[q], hex[0x71], idx[81], width[5], first pixel[16], offset[352/0x160]
        //  .....
        //  .....
        //  .XXXX
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  .XXXX
        //  ....X
        //  ....X
        0xF8, 0xC6, 0x31, 0x78, 0x42, 

        //  ....   char[r], hex[0x72], idx[82], width[4], first pixel[12], offset[357/0x165]
        //  ....
        //  ....
        //  X.XX
        //  XX..
        //  X...
        //  X...
        //  X...
        //  X...
        //  ....
        //  ....
        0xBC, 0x88, 0x88, 

        //  ....   char[s], hex[0x73], idx[83], width[4], first pixel[13], offset[360/0x168]
        //  ....
        //  ....
        //  .XXX
        //  X...
        //  XX..
        //  ..XX
        //  ...X
        //  XXX.
        //  ....
        //  ....
        0xF1, 0x86, 0x3C, 

        //  ....   char[t], hex[0x74], idx[84], width[4], first pixel[5], offset[363/0x16B]
        //  .X..
        //  .X..
        //  XXXX
        //  .X..
        //  .X..
        //  .X..
        //  .X..
        //  ..XX
        //  ....
        //  ....
        0x89, 0xE8, 0x88, 0x86, 

        //  .....   char[u], hex[0x75], idx[85], width[5], first pixel[15], offset[367/0x16F]
        //  .....
        //  .....
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  X...X
        //  .XXXX
        //  .....
        //  .....
        0x8C, 0x63, 0x18, 0xBC, 

        //  .....   char[v], hex[0x76], idx[86], width[5], first pixel[15], offset[371/0x173]
        //  .....
        //  .....
        //  X...X
        //  X...X
        //  .X.X.
        //  .X.X.
        //  ..X..
        //  ..X..
        //  .....
        //  .....
        0x8C, 0x54, 0xA2, 0x10, 

        //  .......   char[w], hex[0x77], idx[87], width[7], first pixel[21], offset[375/0x177]
        //  .......
        //  .......
        //  X..X..X
        //  X..X..X
        //  X.X.X.X
        //  X.X.X.X
        //  .X...X.
        //  .X...X.
        //  .......
        //  .......
        0x93, 0x26, 0xAD, 0x54, 0x48, 0x80, 

        //  .....   char[x], hex[0x78], idx[88], width[5], first pixel[15], offset[381/0x17D]
        //  .....
        //  .....
        //  X...X
        //  .X.X.
        //  ..X..
        //  ..X..
        //  .X.X.
        //  X...X
        //  .....
        //  .....
        0x8A, 0x88, 0x45, 0x44, 

        //  .....   char[y], hex[0x79], idx[89], width[5], first pixel[15], offset[385/0x181]
        //  .....
        //  .....
        //  X...X
        //  .X.X.
        //  .X.X.
        //  .X.X.
        //  ..X..
        //  ..X..
        //  ..X..
        //  .X...
        0x8A, 0x94, 0xA2, 0x10, 0x88, 

        //  ....   char[z], hex[0x7A], idx[90], width[4], first pixel[12], offset[390/0x186]
        //  ....
        //  ....
        //  XXXX
        //  ...X
        //  ..X.
        //  .X..
        //  X...
        //  XXXX
        //  ....
        //  ....
        0xF1, 0x24, 0x8F, 
    } // .code
}; // Verdana11
