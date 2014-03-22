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
 * @file           PollButtons.c
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
#include "emx/Buttons.h"
#include "emx/Feedback.h"

#include <avr/io.h>
#include <util/delay.h>

#include <stdint.h>

uint8_t pollButtons(uint8_t aMask, uint8_t aAttribs)
{
    // waits for one of the buttons being allowed in mask to be pressed
    // mask can be
    // 0b1000nnnn for first button
    // 0b0100nnnn for second button ... and so on

    static uint8_t lastButtons;

    uint8_t accel = aAttribs & BF_ACCEL;

    if (aAttribs & BF_RESET) // start from scratch ?
        lastButtons = 0;

    uint8_t newButtons = 0;
    uint8_t count = 0;

    // we allow 10 keypresses/sec == 100ms/keypress == 2ms delay

    while (count < 50)
    {
        newButtons = ~PINB;        // e.g.: (~1101xxxx) = 0010xxxx
        newButtons &= 0xF0;       //     = 00100000
        if (aAttribs & BF_NOBLOCK)
        {
            lastButtons = 0;
            return newButtons;
        }
        
        if ((newButtons & aMask) != 0x00)
        {
            if (newButtons == lastButtons)
                ++count;
            else
            {        
                count = 0;
                accel = 0;
                lastButtons = newButtons;
            }
            _delay_ms(2);
        }
    }

    if (aAttribs & BF_DELAY)
        _delay_ms(100);
    feedback(1, BEEP_TICK, WITH_BUZZER);
    return newButtons | accel;
} // pollButtons

