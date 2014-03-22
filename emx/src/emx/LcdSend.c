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
 * @file           LcdSend.c
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
#include "emx/Hardware.h"
#include "emx/Lcd.h"


void lcdSend(LcdSend_t aType, uint8_t aByte)
{
    // all values SRAM
    // direct hardware operations

    LCD_A0 = aType; // 0: command, 1: data
    int8_t i;
    for (i=7; i>=0; --i)
    {
        LCD_SCL = 0;
        LCD_SI = (aByte & (1 << (i))) ? 1 : 0;
        // delays don't seem to be necessary
        // __builtin_avr_delay_cycles(CYCLES_FOR_NANOSECS(250)); // delay 250ns
        LCD_SCL = 1;
        // _delay_us(1);
    }
} // LcdSend
