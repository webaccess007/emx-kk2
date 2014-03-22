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
 * @file           SetIcons.c
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
#include "emx/Buttons.h"
#include "emx/Fonts.h"
#include "emx/Lcd.h"
#include "emx/Menu.h"
#include "emx/Types.h"

void setIcons(IconType_t aType, uint8_t aMask)
{
    const char* icons;
    switch (aType)
    {
        case IT_MENU:
            icons = MENUICONS;
            break;
        case IT_EDIT:
            icons = EDITICONS;
            break;
    }

    uint8_t fontHeight = FONTHEIGHT(ICONFONT);
    uint8_t bottomY = LCDHEIGHT-2-fontHeight;
    lcdBufFillRect(0, bottomY, LCDWIDTH, fontHeight+1, COL_WHITE);

    if (aMask & BT_BACK)  lcdBufPutc(icons[0], &EDITICONFONT,   0, bottomY, COL_BLACK);
    if (aMask & BT_UP)    lcdBufPutc(icons[1], &EDITICONFONT,  35, bottomY, COL_BLACK);
    if (aMask & BT_DOWN)  lcdBufPutc(icons[2], &EDITICONFONT,  70, bottomY, COL_BLACK);
    if (aMask & BT_ENTER) lcdBufPutc(icons[3], &EDITICONFONT, 115, bottomY, COL_BLACK);

} // setIcons
