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
 * @file           PutValue.c
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
#include <emx/Feedback.h>

#include <avr/pgmspace.h>
#include <avr/eeprom.h>

#include <stdint.h>

void putValue(void* aAdr, uint8_t aPType, int32_t* aValue)
{
    union {
        void*     adr; 
        uint8_t*  u8Adr;
        uint16_t* u16Adr;
        //        uint32_t* u32Adr;
    } a;

    a.adr = aAdr;
    if (ISEEADR(aPType))
    {
        if (IS8BIT(aPType))
            eeprom_update_byte(aAdr, ISSIGNED(aPType) ? (int8_t) *aValue : (uint8_t) *aValue);
        else if(IS16BIT(aPType))
            eeprom_update_word(aAdr, ISSIGNED(aPType) ? (int16_t) *aValue : (uint16_t) *aValue);
#ifdef WITH_EE32VALUES
        else if(IS32BIT(aPType))
            eeprom_update_dword(aAdr, ISSIGNED(aPType) ? *aValue : (uint32_t) *aValue);
#endif
    } else if (ISRAMADR(aPType))
    {
        if (IS8BIT(aPType))
            *a.u8Adr = ISSIGNED(aPType) ? (int8_t) *aValue : (uint8_t) *aValue;
        else if(IS16BIT(aPType))
            *a.u16Adr = ISSIGNED(aPType) ? (int16_t) *aValue : (uint32_t) *aValue;
#ifdef WITH_EE32VALUES
        else if(IS32BIT(aPType))
            *a.u32Adr = ISSIGNED(aPType) ?  *aValue : (uint32_t) *aValue;
#endif
    }
    feedback(1, BLINK_MEDIUM, WITH_LED1);
} // getValue


