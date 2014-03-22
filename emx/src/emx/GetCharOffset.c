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
 * @file           GetCharOffset.c
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
#include "emx/EmxFont.h"
#include "emx/Types.h"

#include <stdint.h>
#include <avr/pgmspace.h>


uint16_t getCharOffset(const EmxFont_t* aFont, uint8_t aIdx)
{
    uint8_t att = getAttribs(aFont);
    uint16_t offset;
    if (att & FT_FIXED)
    {
        // TBC!
        offset = ((pgm_read_byte(&aFont->wb.fixedWidth) *
                   pgm_read_byte(&aFont->height)) + 7) / 8;
    } else
    {
        const uint8_t* valueMap = (uint8_t*) pgm_read_word(&aFont->offsetIdx);
        uint8_t bits = (pgm_read_byte(&aFont->foBits) & 0x0F);
        offset = getBitCodedNumber(valueMap, aIdx, bits);                    
    }
    return offset;
} // getCharWidth;

