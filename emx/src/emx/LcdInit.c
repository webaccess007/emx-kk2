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
 * @file           LcdInit.c
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
#include "emx/Lcd.h"
#include "emx/Hardware.h"
#include "emx/Feedback.h"

#include <avr/pgmspace.h>
#include <util/delay.h>

const uint8_t LcdInitString[] PROGMEM   = 
    { LCMD_SET_BIAS_9,
      LCMD_SET_ADC_NORMAL,
      LCMD_SET_DISP_START_LINE,
      LCMD_SET_POWER_CONTROL | 0x04,                 // set on power registers one after trhe 
      LCMD_SET_POWER_CONTROL | (0x04 | 0x02),
      LCMD_SET_POWER_CONTROL | ((0x04 | 0x02) | 0x01),
      LCMD_SET_RESISTOR_RATIO,
      LCMD_DISPLAY_ON, 
      LCMD_SET_DISP_NORMAL,
      LCMD_SET_ALLPTS_NORMAL,
      LCMD_RMW,      
      LCMD_SET_STATIC_OFF, 0x00,    // 0x00: complete the sequence
      LCMD_SET_BOOSTER_FIRST, 0x00, // 0x00: complete the sequence
    };


void lcdInit(void)
{


    // set LCD pins according to this layout:
    // LCD_SI	     REGISTER_BIT(PORTD, 1)
    // LCD_SI_DIR   REGISTER_BIT(DDRD,  1)
    // LCD_SCL	     REGISTER_BIT(PORTD, 4)
    // LCD_SCL_DIR  REGISTER_BIT(DDRD,  4)
    // LCD_CS1	     REGISTER_BIT(PORTD, 5)
    // LCD_CS1_DIR  REGISTER_BIT(DDRD,  5)
    // LCD_RES	     REGISTER_BIT(PORTD, 6)
    // LCD_RES_DIR  REGISTER_BIT(DDRD,  6)
    // LCD_A0	     REGISTER_BIT(PORTD, 7)
    // LCD_A0_DIR   REGISTER_BIT(DDRD,  7)

    // we do this in one wash without affecting the other pins
    DDRD  |= 0b11110010; 
    // _delay_ms(63);       // Pause while pullups rise --- is that really necessary?
    _delay_ms(1);           // should suffice ...
    
    // Toggle RST low to reset and CS low so it'll listen to us
    LCD_CS1 = 1;    // GLCD control bits
    LCD_SCL = 1;
    LCD_RES = 1;    // LCD-Reset High: normal operation (already done above with )

    LCD_CS1 = 0;
    LCD_RES = 0;    // LCD-Reset Low:  init
    _delay_ms(100); // was: 500
    LCD_RES = 1;    // LCD-Reset High: normal operation

    const uint8_t* lcdInitPtr = LcdInitString;

    // Send command sequence
    for (int i = 0; i < sizeof(LcdInitString); ++i)
    {
        uint8_t command = (uint8_t)pgm_read_byte(lcdInitPtr);
        lcdSend(LCD_COMMAND, command);
        if ((command & LCMD_SET_POWER_CONTROL) == LCMD_SET_POWER_CONTROL)
            _delay_ms(50);
        ++lcdInitPtr;
    }
    lcdSetContrast(0x26);
    LCD_BUF_CLEAR();
    LCD_CLEAR();
} // lcdInit
