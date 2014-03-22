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
 * @file           Hardware.h
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
#ifndef HARDWARE_H
#define HARDWARE_H

#include "emx/Types.h"
#include "avr/io.h"

#define START_TIMER0() TIMSK |= (1<<TOIE0)
#define STOP_TIMER0()  TIMSK &= ~(1<<TOIE0)


#define LCD_SI	     REGISTER_BIT(PORTD, 1)
#define LCD_SI_DIR   REGISTER_BIT(DDRD,  1)
#define LCD_SCL	     REGISTER_BIT(PORTD, 4)
#define LCD_SCL_DIR  REGISTER_BIT(DDRD,  4)
#define LCD_CS1	     REGISTER_BIT(PORTD, 5)
#define LCD_CS1_DIR  REGISTER_BIT(DDRD,  5)
#define LCD_RES	     REGISTER_BIT(PORTD, 6)
#define LCD_RES_DIR  REGISTER_BIT(DDRD,  6)
#define LCD_A0	     REGISTER_BIT(PORTD, 7)
#define LCD_A0_DIR   REGISTER_BIT(DDRD,  7)

#define LED1PORT    PORTB
#define LED1PIN     3

#define BUZZERPORT  PORTB
#define BUZZERPIN   1

#define LED1         REGISTER_BIT(PORTB, 3)     // Red LED
#define LED1_DIR     REGISTER_BIT(DDRB,3)
#define BUZZER       REGISTER_BIT(PORTB, 1) // LVA output (buzzer)
#define BUZZER_DIR   REGISTER_BIT(DDRB,1)
#define BUTTON1      REGISTER_BIT(PINB,7)                // Button 1
#define BUTTON1_DIR  REGISTER_BIT(DDRB,7)
#define BUTTON2      REGISTER_BIT(PINB,6)                // Button 2
#define BUTTON2_DIR  REGISTER_BIT(DDRB,6)
#define BUTTON3      REGISTER_BIT(PINB,5)                // Button 3
#define BUTTON3_DIR  REGISTER_BIT(DDRB,5)
#define BUTTON4      REGISTER_BIT(PINB,4)                // Button 4
#define BUTTON4_DIR  REGISTER_BIT(DDRB,4)

// LVA: low voltage alarm
#define LVA BUZZER

// terminate include guard
#endif
