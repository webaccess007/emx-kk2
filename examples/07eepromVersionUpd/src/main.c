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
 * @file           main.c
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
#include <emx/Fonts.h>
#include <emx/Lcd.h>
#include <emx/Menu.h>
#include <emx/Buttons.h>

#include <avr/pgmspace.h>
#include <util/delay.h>

const char TX_Copyright[]        PROGMEM = "Copyright";
const char TX_SubMenu[]          PROGMEM = "Show submenu";
const char TX_EepromVersionRo[]  PROGMEM = "Show EEPROM version";
const char TX_EepromVersion[]    PROGMEM = "Edit EEPROM version";
const char TX_SetContrast[]      PROGMEM = "Set contrast";
const char TX_ScaledVoltage[]    PROGMEM = "Voltage alarm";

const char TX_EmxLogo[]          PROGMEM = "Show EMX logo";
const char TX_License[]          PROGMEM = "Show license";

typedef struct EEProm
{
    uint8_t EEStart; // magic byte
    uint8_t m_contrast;
} EEProm_t;

// this is only a DECLARATION, no definition: a fake to enable the compiler to calculate EEprom adresses.
extern EEProm_t EEProm;

#define EEP(name) ((uint8_t*) ((uint8_t*) &EEProm.name - &EEProm.EEStart))

const U8ValP_t EEVersion PROGMEM = {
    .m_dataP = (uint8_t*) EEP(EEStart),
};

uint8_t Copyright(MenuState_t* aMs)
{
    LCD_BUF_CLEAR();
    lcdBufPuts(AT_PGM, PSTR("menu system,\n"
                            "framework and font\n"
                            "2013-2014 by\n"
                            "Edgar (emax) Hermanns"),
               &Verdana11, 0, 0, COL_BLACK);
    lcdUpdate(1);
    pollButtons(0xFF, 1);
    return 1;
}

const Menu_t InfoMenu PROGMEM = {
    .m_entryCount = 2,
    .m_entries = {
        { TX_EmxLogo,       VOID(0) },
        { TX_License,       VOID(0) },
    }, // m_entries
}; // VersionMenu

const Menu_t TopMenu PROGMEM = {
    .m_entryCount = 6,
    .m_entries = {
        { TX_Copyright,       FUNC(Copyright) },
        { TX_SubMenu,         MENU(InfoMenu) },
        { TX_EepromVersionRo, U8PER(EEVersion) },
        { TX_EepromVersion,   U8PE(EEVersion) },
        { TX_SetContrast,     VOID(0) },
        { TX_ScaledVoltage,   VOID(0) },
    }, // m_entries
}; // TopMenu

int main(void)
{
    _delay_ms(100);  // wait for voltages and levels to settle
    lcdInit();
    BUTTON_INIT();
    while(1)
        displayMenu(&TopMenu, BT_ALL);
} // main
