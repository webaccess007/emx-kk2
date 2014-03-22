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
 * @file           Feedback.h
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
#ifndef FEEDBACK_H
#define FEEDBACK_H

#include "emx/Types.h"
#include "emx/Hardware.h"

#include <stdint.h>
#include <avr/io.h>

#define WITH_LED1     &LED1PORT, (1 << LED1PIN)
#define WITH_BUZZER   &BUZZERPORT, (1 << BUZZERPIN)

#define BEEP_TICK   1
#define BEEP_FAST   5
#define BEEP_MEDIUM 10 
#define BEEP_SLOW   20

#define BLINK_FAST   6
#define BLINK_MEDIUM 13
#define BLINK_SLOW   26

void feedback(uint8_t aCount, uint8_t a10Ms, volatile uint8_t *port, uint8_t aPin);

#endif
