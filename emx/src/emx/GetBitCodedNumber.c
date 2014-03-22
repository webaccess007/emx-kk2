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
 * @file           GetBitCodedNumber.c
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
#include "emx/Types.h"

#include <stdint.h>
#include <avr/pgmspace.h>

uint16_t getBitCodedNumber(const unsigned char* bitCode, uint8_t idx, uint8_t bits)
{
    /**
       extracts a number out of a bitcoded field of values where the size of the
       numbers is defined in 'bits' which can be any number from from 1 to 16.
       Example for a bitcoded field which contains 5 numbers I, J, K, L, M with 
       a size of 3 bits each = 15 bits (metacode):
        pattern      : bits = { 0bIIIJJJKK, 0bKLLLMMMx }  
        bitcode value: bits = {       0x67,       0x89 }
        binary       : bits = { 0b01100111, 0b10001001 } = 011-001-111-000-100-1 
        fields       :                                     III-JJJ-KKK-LLL-MMM-x
        yields values:                                      3   1   7   0   4
    */

    uint16_t startBit = bits*idx; // e.g. bits=7, idx=1: 14 
    uint8_t  startByte = startBit/8;
    startBit %= 8;

    uint8_t inBit = (0x80>>startBit);
    const uint8_t* codePtr = &bitCode[startByte];
    uint16_t number = 0;
    --bits;
    uint16_t value = (1<<bits);
    uint8_t data = pgm_read_byte(codePtr);
    while (value)
    {
        if (data & inBit)
            number |= value;

        if (inBit == 0x01) // last bit processed ?
        {
            inBit = 0x80;
            ++codePtr;
            data = pgm_read_byte(codePtr);
        }
        else
            inBit >>= 1;
        value >>= 1;
    }
    return number;
} // getBitCodedNumber
