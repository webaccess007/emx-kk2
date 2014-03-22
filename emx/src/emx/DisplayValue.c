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
 * @file           DisplayValue.c
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
#include "emx/Config.h"
#include "emx/Buttons.h"
#include "emx/Menu.h"
#include "emx/Lcd.h"
#include "emx/Fonts.h"
#include "emx/Feedback.h"

#include <stdlib.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>

void displayValue(AdrType_t aAdrType, const char* buf, uint8_t aY, uint8_t aColor)
{    
    uint8_t pixels = lcdBufPuts(aAdrType, buf, &MENUFONT, 0, 0, LA_CHARWIDTHONLY);
    uint8_t xRight = LCDWIDTH-pixels;
    if (aColor == COL_WHITE)
        lcdBufFillRect(xRight, aY, pixels, 
                       FONTHEIGHT(MENUFONT), 
                       COL_BLACK);
    lcdBufPuts(aAdrType, buf, &MENUFONT, xRight, aY, aColor);
}

