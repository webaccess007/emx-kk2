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
#include <avr/eeprom.h>

#include <util/delay.h>

const char TX_Copyright[]        PROGMEM = "Copyright";
const char TX_SubMenu[]          PROGMEM = "Show submenu";
const char TX_EepromVersionRo[]  PROGMEM = "Show EEPROM version";
const char TX_EepromVersion[]    PROGMEM = "Edit EEPROM version";
const char TX_SetContrast[]      PROGMEM = "Set contrast";
const char TX_ScaledVoltage[]    PROGMEM = "Voltage alarm";
const char TX_Protocol[]         PROGMEM = "Protocol";

const char TX_Futaba[]           PROGMEM = "Futaba";
const char TX_Spectrum[]         PROGMEM = "Spectrum";
const char TX_Graupner[]         PROGMEM = "Graupner";
const char TX_Jeti[]             PROGMEM = "Jeti";
const char TX_Multiplex[]        PROGMEM = "Multiplex";

const char TX_EmxLogo[]          PROGMEM = "Show EMX logo";
const char TX_License[]          PROGMEM = "Show license";

const char TX_ProfileNo[]       PROGMEM = "Profile No.";
const char TX_PValue[]          PROGMEM = "P-Value";
const char TX_IValue[]          PROGMEM = "I-Value";
const char TX_DValue[]          PROGMEM = "D-Value";

const char TX_Curve[]           PROGMEM = "Curve";
const char TX_Flat[]            PROGMEM = "Flat";
const char TX_Normal[]          PROGMEM = "Normal";
const char TX_Steep[]           PROGMEM = "Steep";

typedef struct
{
    uint8_t          m_curveType;
    uint8_t          m_pValue;
    uint8_t          m_iValue;
    uint8_t          m_dValue;
} Profile_t;

typedef struct EEProm
{
    uint8_t EEStart; // magic byte
    uint8_t m_contrast;
    uint8_t m_voltageAlarm;
    uint8_t m_protocol;
    uint8_t m_curProfile;
    Profile_t m_profiles[3];
} EEProm_t;

// this is only a DECLARATION, no definition: a fake to enable the compiler to calculate EEprom adresses.
extern EEProm_t EEProm;

#define EEP(name) ((uint8_t*) ((uint8_t*) &EEProm.name - &EEProm.EEStart))
// return the offset of a variable in Profile_t array
#define EEP_PRV(name) (EEP(m_profiles[0].name) - EEP(m_profiles[0]))

const U8ValP_t EEVersion PROGMEM = {
    .m_dataP = (uint8_t*) EEP(EEStart),
};

void setContrast(CallbackType_t aCbType, void* s32)
{
    /**
     * s32 points to an int32_t value handled by the editor
     * - as opposed to the value-address itself.
     **/

    // for the contrast, we only need 8 bits from the editor value
    uint8_t val = ((S32MMSVal_t*) s32)->m_val;

    // pressed-key is LHS-nibble of aCbType
    uint8_t key = aCbType & 0xF0;

    // callbacktype is in RHS(right-hand-side)-nibble of aCbType
    switch (aCbType & 0x0F) // only use RHS nibble
    {
        case CT_ENTRY:               // entry to to the editor: nothing to do
            break;

        case CT_CHANGE:              // the value was changed in the editor
            if (key == BT_ENTER)     // value committed: update EEPROM
                eeprom_update_byte((uint8_t*)EEP(m_contrast), val);
            else                     // there was a change with BT_UP or BT_DOWN
                lcdSetContrast(val); // 'live-update' the contrast
            break;
        case CT_RETURN:              // editor is about to be closed
            lcdSetContrast(val);
            break;
    } // switch
} // setContrast

void* getPrfDynDataP(void* aAdressOffset)
{
    // the aAdressOffset value contains the offset from
    // &Eeconfig.m_fc[0] to the FC-variable in question.
    // To obtain this offset, the macro EEP_FCV(varname) is used.
    // EEP_FCV -> EepromPointer to FlightControl-Variable

    // get the current profile
    uint8_t curProf = eeprom_read_byte(EEP(m_curProfile));
    // return the corresponding variable adress
    return aAdressOffset + ( (int16_t) EEP(m_profiles[curProf-1])); // profiles 0,1,2 are coded 1,2,3
}

const U8MMValPCb_t Contrast PROGMEM = {
    .m_min = 28,
    .m_max = 50,
    .m_dataP = (uint8_t*) EEP(m_contrast),
    .m_callback = &setContrast,
}; // Contrast

const U8MMSValP_t Voltage PROGMEM = {
    .m_min = 51,
    .m_max = 125,
    .m_scale = 1,
    .m_dataP = (uint8_t*) EEP(m_voltageAlarm),
};

// dynamic pointers
const U8MMValDP_t PValue PROGMEM = {
    .m_min = 1,
    .m_max = 100,
    // this value is passed to getDynDataP (see GetDynDataP function)
    .m_dynDataInfo = (uint8_t*) EEP_PRV(m_pValue),
    .m_callback = &getPrfDynDataP
};
const U8MMValDP_t IValue PROGMEM = {
    .m_min = 0,
    .m_max = 127,
    // this value is passed to getDynDataP (see GetDynDataP function)
    .m_dynDataInfo = (uint8_t*) EEP_PRV(m_iValue),
    .m_callback = &getPrfDynDataP
};
const U8MMValDP_t DValue PROGMEM = {
    .m_min = 20,
    .m_max = 80,
    // this value is passed to getDynDataP (see GetDynDataP function)
    .m_dynDataInfo = (uint8_t*) EEP_PRV(m_dValue),
    .m_callback = &getPrfDynDataP
};

const U8MMValP_t CurProfile PROGMEM = {
    .m_min = 1,
    .m_max = 3,
    .m_dataP = (uint8_t*) EEP(m_curProfile),
};

const ITextListDP_t Curve PROGMEM = {
    .m_entryCount  = 3,
    .m_dynDataInfo = (uint8_t*) EEP_PRV(m_curveType),
    .m_callback    = &getPrfDynDataP,
    .m_texts       = {
        TX_Flat,
        TX_Normal,
        TX_Steep,
    },
};

const ITextListP_t Protocol PROGMEM = {
    .m_entryCount =5,
    .m_idxP       = (uint8_t*) EEP(m_protocol),
    .m_texts      = {
        TX_Futaba,
        TX_Spectrum,
        TX_Graupner,
        TX_Jeti,
        TX_Multiplex
    },
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
}; // InfoMenu

const Menu_t TopMenu PROGMEM = {
    .m_entryCount = 11,
    .m_entries = {
        { TX_Copyright,       FUNC(Copyright) },
        { TX_SubMenu,         MENU(InfoMenu) },
        { TX_EepromVersionRo, U8PER(EEVersion) },
        { TX_EepromVersion,   U8PE(EEVersion) },
        { TX_SetContrast,     U8MMPEC(Contrast) },
        { TX_ScaledVoltage,   U8MMSPE(Voltage) },
        { TX_Protocol,        ITLPE(Protocol) },
        { TX_ProfileNo,       U8MMPE(CurProfile) },
        { TX_Curve,           ITLDPE(Curve) },
        { TX_PValue,          U8MMDPE(PValue)  },
        { TX_IValue,          U8MMDPE(IValue)  },
        { TX_DValue,          U8MMDPE(DValue)  },
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
