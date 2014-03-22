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
 * @file           Menu.h
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
#ifndef MENU_H
#define MENU_H

#include "emx/Types.h"
#include "emx/EmxFont.h"

#include <stdint.h>

#define EDITFONT  Verdana19
#define MENUFONT  Verdana11
#define EDITICONFONT Verdana11

#define MENUICONS "\\^_`"
#define EDITICONS "\\^_`"


//#define MENU(a)     .m_pType=0, .m_typeHandler=((void*) HND_MENU), .m_ptr = { .m_subMenu = &a }
#define MENU(a)     .m_pType=0, .m_typeHandler=((void*) HND_MENU),      .m_ptr = { .m_subMenu = &a }
#define FUNC(a)     .m_pType=0, .m_typeHandler=((void*) HND_FUNC), .m_ptr = { .m_func    = &a }
#define EXIT(a)     .m_pType=0, .m_typeHandler=((void*) HND_EXIT), .m_ptr = { .m_func    = a  }
#define VOID(a)     .m_pType=((RW(RO))),        \
                                .m_typeHandler=((void*) HND_VOID), .m_ptr = { .m_value   =  a }
#define ITLPE(a)    .m_pType=((BPT(TEXT))     | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                              .m_typeHandler=&editITLP,            .m_ptr = { .m_voidAdr = &a }
#define ITLDPE(a)   .m_pType=((BPT(TEXT))     | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                              .m_typeHandler=&editITLDP,           .m_ptr = { .m_voidAdr = &a }
#define U8PE(a)     .m_pType=((BPT(NUMBER))   | \
                              (BC(8BIT))      | \
                              (SGN(UNSIGNED)) | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                              .m_typeHandler=&editP,               .m_ptr = { .m_voidAdr = &a }
#define S8PE(a)     .m_pType=((BPT(NUMBER))   | \
                              (BC(8BIT))      | \
                              (SGN(SIGNED))   | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                              .m_typeHandler=&editP,               .m_ptr = { .m_voidAdr = &a }
#define U8PER(a)    .m_pType=((BPT(NUMBER))   | \
                              (BC(8BIT))      | \
                              (SGN(UNSIGNED)) | \
                              (STG(EEPROM))   | \
                              (RW(RO))),        \
                               .m_typeHandler=&displayP,           .m_ptr = { .m_voidAdr = &a }
#define S8PER(a)    .m_pType=((BPT(NUMBER))   | \
                              (BC(8BIT))      | \
                              (SGN(SIGNED))   | \
                              (STG(EEPROM))   | \
                              (RW(RO))),        \
                               .m_typeHandler=&displayP,           .m_ptr = { .m_voidAdr = &a }
#define U8MMPE(a)   .m_pType=((BPT(NUMBER))   | \
                              (BC(8BIT))      | \
                              (SGN(UNSIGNED)) | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                               .m_typeHandler=&editMMP,            .m_ptr = { .m_voidAdr = &a }
#define S8MMPE(a)   .m_pType=((BPT(NUMBER))   | \
                              (BC(8BIT))      | \
                              (SGN(SIGNED))   | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                               .m_typeHandler=&editMMP,            .m_ptr = { .m_voidAdr = &a }
#define U8MMSPE(a)  .m_pType=((BPT(NUMBER))   | \
                              (BC(8BIT))      | \
                              (SGN(UNSIGNED)) | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                               .m_typeHandler=&editMMSP,           .m_ptr = { .m_voidAdr = &a }
#define S8MMSPE(a)  .m_pType=((BPT(NUMBER))   | \
                              (BC(8BIT))      | \
                              (SGN(SIGNED))   | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                               .m_typeHandler=&editMMSP,           .m_ptr = { .m_voidAdr = &a }
#define U8MMDPE(a)  .m_pType=((BPT(NUMBER))   | \
                              (BC(8BIT))      | \
                              (SGN(UNSIGNED)) | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                               .m_typeHandler=&editMMDP,           .m_ptr = { .m_voidAdr = &a }
#define S8MMDPE(a)  .m_pType=((BPT(NUMBER))   | \
                              (BC(8BIT))      | \
                              (SGN_SIGNED   ) | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                               .m_typeHandler=&editMMDP,           .m_ptr = { .m_voidAdr = &a }
#define U8MMPEC(a)  .m_pType=((BPT(NUMBER))   | \
                              (BC(8BIT))      | \
                              (SGN(UNSIGNED)) | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                               .m_typeHandler=&editMMPC,           .m_ptr = { .m_voidAdr = &a }
#define U16MMSPE(a) .m_pType=((BPT(NUMBER))   | \
                              (BC(16BIT))     | \
                              (SGN(UNSIGNED)) | \
                              (STG(EEPROM))   | \
                              (RW(RW))),        \
                               .m_typeHandler=&editMMSP,           .m_ptr = { .m_voidAdr = &a }

// menu rc-codes
#define MR_EXIT    0x80
#define MR_REPEAT  0x40

typedef struct MenuState_s {
    uint8_t                   m_curX;
    uint8_t                   m_curY;
    uint8_t                   m_dspX;
    uint8_t                   m_dspY;
    uint8_t                   m_fontHeight;
    uint8_t                   m_selPType;
    const struct me*          m_selEntry;
    const EmxFont_t*          m_font;
} MenuState_t;

typedef uint8_t (*MenuFunctor_t)(MenuState_t* aMs);
typedef union {
        const void*           m_voidAdr;
        const uint8_t         m_value;
        const MenuFunctor_t   m_func;
        const struct Menu_s*  m_subMenu;
        const ITextListP_t*   m_iTextListP;
        const U8ValP_t*       m_u8ValP;
        const U8MMValP_t*     m_u8MMValP;
        const U8MMSValP_t*    m_u8MMSValP;
        const U8MMValDP_t*    m_u8MMValDP;
        const S8MMValP_t*     m_s8MMValP;
        const S8MMSValP_t*    m_s8MMSValP;
        const S8MMValDP_t*    m_s8MMValDP;
        const U8MMValPCb_t*   m_u8MMValPCb;
        const U16MMSValP_t*   m_u16MMSValP;
        const S16MMSValP_t*   m_s16MMSValP;
} PtrUnion_t;

typedef void    (*TypeHandler_t)(HandlerType_t aHandlerType, uint8_t PType, PtrUnion_t* aPtrUnionAdr,
                                 uint8_t aY, uint8_t aColor);

typedef struct me {
    const char*               m_text;
    uint8_t                   m_pType;
    TypeHandler_t             m_typeHandler;
    PtrUnion_t                m_ptr;
} MenuEntry_t;

typedef struct Menu_s {
    const uint8_t             m_entryCount;
    const MenuEntry_t         m_entries[];
} Menu_t;

// function prototypes
void     getValue(const void* aAdr, uint8_t aPType, int32_t* aResult);
void     putValue(void* aDdr, uint8_t aPType, int32_t* aValue);

void*    pgmToRamMMDP(uint8_t aPType, PtrUnion_t* aPtrUnion, S32MMSValCb_t *aS32MMSValCb);
void*    pgmToRamMMP(uint8_t aPType, PtrUnion_t* aPtrUnion,  S32MMSValCb_t *aS32MMSValCb);
void*    pgmToRamMMPC(uint8_t aPType, PtrUnion_t* aPtrUnion, S32MMSValCb_t *aS32MMSValCb);
void*    pgmToRamMMSP(uint8_t aPType, PtrUnion_t* aPtrUnion, S32MMSValCb_t *aS32MMSValCb);
void*    pgmToRamP(uint8_t aPType, PtrUnion_t* aPtrUnion,    S32MMSValCb_t *aS32MMSValCb);
void*    pgmToRamITLP(uint8_t aPType, PtrUnion_t* aPtrUnion, ITextListIdx_t *aITextListIdx);
void*    pgmToRamITLDP(uint8_t aPType, PtrUnion_t* aPtrUnion, ITextListIdx_t *aITextListIdx);

uint8_t  displayMenu(const Menu_t* aMenu, uint8_t aButtonMask);

void     displayMMDP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     displayMMP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     displayMMPC(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     displayMMSP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     displayP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     displayITLP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     displayITLDP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);

void     editMMDP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     editMMP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     editMMPC(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     editMMSP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     editP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     editITLP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     editITLDP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);

void     handlerU8PE(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     handlerU8PER(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     handlerU8MMPE(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     handlerU8MMDPE(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     handlerU8MMSPE(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     handlerU8MMPEC(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     handlerU16MMSPE(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     handlerITLPE(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     handlerS8MMPE(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);
void     handlerS8MMDPE(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aAdr,uint8_t aY, uint8_t aCol);


void     displayVar(const MenuEntry_t* aMe, uint8_t aY, uint8_t fgColor);
void     displayValue(AdrType_t aAdrType, const char* aBuf, uint8_t aY, uint8_t aColor);
void     editVar(uint8_t aPType, void* aAddress, uint8_t aY);
uint8_t  editNumber(S32MMSValCb_t* s32, uint8_t aY);
uint8_t  editTextList(ITextListIdx_t* aITextListIdx, uint8_t aY);
void     drawEditFrame(uint8_t aX, uint8_t aY, uint8_t aWidth, uint8_t aHeight);
#endif
