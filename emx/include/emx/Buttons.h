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
 * @file           Buttons.h
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
#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdint.h>

// button masks
#define BT_NONE  0b00000000
#define BT_BACK  0b10000000 // 0x80    S1 pressed
#define BT_UP    0b01000000 // 0x40    S2 pressed
#define BT_DOWN  0b00100000 // 0x20    S3 pressed
#define BT_ENTER 0b00010000 // 0x10    S4 pressed
#define BT_ALL   0b11110000 // 0x10    any button pressed

// some alias names for edit-mode
#define BT_MINUS BT_DOWN 
#define BT_PLUS  BT_UP   

// button flags

#define BF_DELAY       0x01
#define BF_NOBLOCK     0x02
#define BF_ACCEL       0x04
#define BF_RESET       0x08

#define BUTTON_INIT() { DDRB  &= 0b00001111; PORTB |= 0b11110000; }

uint8_t pollButtons(uint8_t aMask, uint8_t aDelayFirst);

// terminate include guard
#endif
