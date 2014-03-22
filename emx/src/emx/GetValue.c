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
 * @file           GetValue.c
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
#include <emx/Types.h>

#include <avr/pgmspace.h>
#include <avr/eeprom.h>

#include <stdint.h>

void getValue(const void* aAdr, uint8_t aPType, int32_t* aResult)
{
    IntValueUnion_t v;

    if(IS8BIT(aPType))
    {
        // read m_val: EEPROM or RAM or PGM
        v.m_u8Val = ISEEADR(aPType) ? (uint8_t) eeprom_read_byte(aAdr) : 
            ISRAMADR(aPType) ? *((uint8_t*) aAdr) : pgm_read_byte(aAdr);
        *aResult = ISSIGNED(aPType) ? (int8_t) v.m_u8Val : (uint8_t) v.m_u8Val; 
    }
    else if (IS16BIT(aPType))
    {
        // read m_val: EEPROM or RAM or PGM
        v.m_u16Val = ISEEADR(aPType) ? (uint16_t) eeprom_read_word(aAdr) : 
            ISRAMADR(aPType) ? *((uint16_t*) aAdr) : pgm_read_word(aAdr);
        *aResult = ISSIGNED(aPType) ? (int16_t) v.m_u16Val : (uint16_t) v.m_u16Val; 
    }
} // getValue

