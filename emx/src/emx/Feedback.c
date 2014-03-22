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
 * @file           Feedback.c
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
#include "emx/Feedback.h"
#include "emx/Hardware.h"

#include <stdint.h>

#include <util/delay.h>


void feedback(uint8_t aCount, uint8_t a10Ms, volatile uint8_t *aPort, uint8_t aMask)
{
    // signal led or buzzer for a10Ms * 10ms, 
    // i.e.: if a10Ms is 5, signal is 50ms
    aCount <<= 1;
    *aPort |= aMask;

    while (aCount > 1)
    {
        uint8_t delays = a10Ms;
        while (delays)
        {
            _delay_ms(10);
            --delays;
        }

        *aPort ^= aMask;  // toggle
        --aCount;
    }
    //    *aPort &= ~aMask; // set off
} // beep

