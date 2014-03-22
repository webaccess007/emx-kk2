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
 * @file           Lcd.h
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
#ifndef LCD_H
#define LCD_H

#include "emx/Types.h"
#include "emx/EmxFont.h"

#include <stdint.h>
#include <string.h>

// ST7565 commands

#define LCMD_SET_VOLUME_FIRST    0x81
#define LCMD_SET_VOLUME_SECOND   0

#define LCMD_DISPLAY_OFF         0xAE
#define LCMD_DISPLAY_ON          0xAF

// Display start line set: 0b01xxxxxx, xxxxxx=line
#define LCMD_SET_DISP_START_LINE 0x40


#define LCMD_SET_PAGE            0xB0
#define LCMD_SET_COLUMN_UPPER    0x10
#define LCMD_SET_COLUMN_LOWER    0x00

//  ADC (x-adress counter) normal
#define LCMD_SET_ADC_NORMAL      0xA0
//  ADC (x-adress counter) reverse
#define LCMD_SET_ADC_REVERSE     0xA1

#define LCMD_SET_DISP_NORMAL     0xA6
#define LCMD_SET_DISP_REVERSE    0xA7
#define LCMD_SET_ALLPTS_NORMAL   0xA4
#define LCMD_SET_ALLPTS_ON       0xA5

// set LCD driving voltage bias 0b1010001x, x=0: bias 1/9, x=1 bias 1/7
#define LCMD_SET_BIAS_9          0xA2 
#define LCMD_SET_BIAS_7          0xA3

// read modify write
// enter the ReadModifyWrite mode: column address  counter will increase 
// in each "Write Display Data" and will not increase in each "Read Display Data" command
#define LCMD_RMW                 0xE0

// Clear the Read Modify Write mode
#define LCMD_RMW_CLEAR           0xEE

// reset the LCD module
#define LCMD_INTERNAL_RESET      0xE2

// set COM direction: 0b1100 xnnn, 'nnn':don't care
// x=0 normal display
#define LCMD_SET_COM_NORMAL      0xC0
// x=1 flipped in y-direction
#define LCMD_SET_COM_REVERSE     0xC8

// power control, 0b00101xyz, 
//  x=1: voltage-follower on, 
//  y=1: voltage-regulator on, 
//  z=1: voltage-converter on
#define LCMD_SET_POWER_CONTROL   0x28

// internal Voltage regulator ration: 0b00100xxx, xxx: ratio Rb/Ra
#define LCMD_SET_RESISTOR_RATIO  0x24

// seems to be kind of a 'cursor off' command
#define LCMD_SET_STATIC_OFF      0xAC
#define LCMD_SET_STATIC_ON       0xAD
#define LCMD_SET_STATIC_REG      0x0
#define LCMD_SET_BOOSTER_FIRST   0xF8
#define LCMD_SET_BOOSTER_234     0
#define LCMD_SET_BOOSTER_5       1
#define LCMD_SET_BOOSTER_6       3
#define LCMD_NOP                 0xE3
#define LCMD_TEST                0xF0

// ST7565 project parameters
#define LCDWIDTH                128
#define LCDHEIGHT                64

extern uint8_t LcdBuffer[1024];

#define LCD_CLEAR() lcdUpdate(0);
#define LCD_BUF_CLEAR() { memset(LcdBuffer, 0, sizeof(LcdBuffer)); }
#define COL_WHITE 0
#define COL_BLACK 1

typedef enum LcdSend { LCD_COMMAND = 0, LCD_DATA = 1 } LcdSend_t;
typedef enum LcdAttr { 
    LA_UNUSED1       = 0b00010000,
    LA_UNUSED2       = LA_UNUSED1 << 1,
    LA_REVERSE       = LA_UNUSED1 << 2,
    LA_CHARWIDTHONLY = LA_UNUSED1 << 3
} LcdAttr_t;


void    lcdInit(void);
void    lcdSend(LcdSend_t aType, uint8_t aByte);
void    lcdSetContrast(uint8_t aValue);
void    lcdUpdate(uint8_t aMode); // 0 => clear LCD, 1=>write buffer
uint8_t lcdBufPutc(char c, const EmxFont_t* aFont, uint8_t x, uint8_t y, uint8_t aColor);
uint8_t lcdBufPuts(AdrType_t aAdrType, const char* s, const EmxFont_t* aFont, uint8_t x, uint8_t y, uint8_t aColor);
void    lcdBufDrawrect(uint8_t aX, uint8_t aY, uint8_t aW, uint8_t aH, uint8_t aColor);
void    lcdBufFillRect(uint8_t aX, uint8_t aY, uint8_t aWidth, uint8_t aHeight, uint8_t aColor);
void    lcdBufSetPixel(uint8_t x, uint8_t y, uint8_t color);
void    lcdBufWriteEmxLogo(uint8_t aX, uint8_t aY, uint8_t aColor);
#endif
