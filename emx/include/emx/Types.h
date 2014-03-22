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
 * @file           Types.h
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
#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>
#include <stdint.h>

#define MICROSEC_PER_SEC 1000000UL
#define NANOSEC_PER_CYCLE (MICROSEC_PER_SEC/(F_CPU/1000))
#define CYCLES_FOR_NANOSECS(a) (a/(NANOSEC_PER_CYCLE))


/**
 * value type flags
 */
typedef enum {
    /** 
     * there are two basic pointer types for menu-entries defined:
     * 0: VOID,   not coded: handler = HND_VOID
     * 0: MENU,   not coded: handler = HND_MENU
     * 0: FUNC,   not coded: handler = HND_FUNC
     * 0: NUMBER, a numeric value
     * 1: TEXT,   a text value
     * 1 bit total
     */   
    BPT_TEXT = 0,
    BPT_NUMBER,
} BasicPType_t;

typedef enum {
    /**
     * these type 'abuses' the 'm_handler' variable which normally
     * points to a function-address.
     * BUT: the values used here a below normal flash-adresses 
     * (they would in fact lie in the interrupt-vector) 
     * and can thus be identified as 'special' addresses
     */ 
    HND_VOID = 0,
    HND_MENU,
    HND_FUNC,
    HND_EXIT,
    HND_SPECIAL
} HType_t;

typedef enum {
    /** 
     * three storage types:
     * 0: PGM     (flash)
     * 1: EEPROM  
     * 2: RAM   
     * 2 bits total
     */   
    STG_PGM = 0,
    STG_EEPROM,
    STG_RAM
} StorageType_t;

typedef enum {
    /**
     * for numbers, there is a bitcount information for 8, 16, 24, 32 bit
     * 2 bits total
     */
    BC_8BIT  = 0,
    BC_16BIT,
    BC_24BIT,
    BC_32BIT,
} BitCount_t;

typedef enum {
    /**
     * for numbers, we need signed/unsigned information
     * 1 bit
     */
    SGN_UNSIGNED = 0,
    SGN_SIGNED = 1
} SignType_t;

typedef enum {
    /**
     * read-only or not
     * 1 bit
     */
    RW_RW = 0,
    RW_RO
} RWType_t;

/**
 * define the shifting-bits for each element:
 *
 * For NUMBERS, bit-pattern: TSSCCCsR
 * ------------
 * type         bits and range   rightmost shift
 * ------------ --------------   ------    -------
 * BasicPType_t T   1, range 0:0       0       7-0 = 7
 * Storage_t    SS  2  range 1:2       2       7-2 = 5
 * BitCount_t   CCC 3, range 3:5       5       7-5 = 2
 * SignType_t   s   1, range 6:6       6       7-6 = 1
 * RWType_t     R   1, range 7:7       7       7-7 = 0
 *
 * 
 * For TEXTS, bit-pattern: TSSxxxxR
 * ------------
 * type         bits and range   rightmost shift
 * ------------ --------------   ------    -------
 * BasicPType_t 3, range 0:2       2       7-2 = 5
 * RWType_t     1, range 7:7       7       7-7 = 0
 */

#define BPT_SHIFT   7
#define STG_SHIFT   5
#define BC_SHIFT    2
#define SGN_SHIFT   1
#define RW_SHIFT    0

#define BPT_BITS    (0b00000001 << BPT_SHIFT)
#define STG_BITS    (0b00000011 << STG_SHIFT)
#define BC_BITS     (0b00000111 << BC_SHIFT)
#define SGN_BITS    (0b00000001 << SGN_SHIFT)
#define RW_BITS     (0b00000001 << RW_SHIFT)

#define BPT(type) (BPT_##type << BPT_SHIFT)
#define STG(type) (STG_##type << STG_SHIFT)
#define SGN(type) (SGN_##type << SGN_SHIFT)
#define BC(type)  (BC_##type << BC_SHIFT)
#define RW(type)  (RW_##type << RW_SHIFT)

#define SETSTG(ptype, stgType) ((ptype & ~STG_BITS) | STG(stgType))

#define IS8BIT(ptype)     ((ptype & BC_BITS)  == (BC_8BIT    << BC_SHIFT))
#define IS16BIT(ptype)    ((ptype & BC_BITS)  == (BC_16BIT   << BC_SHIFT))
#define IS32BIT(ptype)    ((ptype & BC_BITS)  == (BC_32BIT   << BC_SHIFT))

#define ISSIGNED(ptype)   ((ptype & SGN_BITS) == (SGN_SIGNED << SGN_SHIFT))
#define ISREADONLY(ptype) ((ptype & RW_BITS)  == (RW_RO      << RW_SHIFT))
#define ISEEADR(ptype)    ((ptype & STG_BITS) == (STG_EEPROM << STG_SHIFT))
#define ISRAMADR(ptype)   ((ptype & STG_BITS) == (STG_RAM    << STG_SHIFT))
#define ISPGMADR(ptype)   ((ptype & STG_BITS) == (STG_PGM    << STG_SHIFT))

#define ISMENUHND(th)     (th == HND_MENU)
#define ISFUNCHND(th)     (th == HND_FUNC)
#define ISVOID(th)        (th == HND_VOID)
#define ISEXIT(th)        (th == HND_EXIT)

typedef enum {
    HT_DISPLAY,
    HT_EDIT,
} HandlerType_t;

typedef enum { 
    AT_PGM = 'P', 
    AT_RAM = 'R' 
} AdrType_t;

typedef enum {
    IT_MENU = 1,
    IT_EDIT 
} IconType_t;

typedef enum {
    CT_ENTRY  = 0x01,
    CT_CHANGE = CT_ENTRY << 1,
    CT_RETURN = CT_ENTRY << 2,
} CallbackType_t;

typedef void  (*CallbackFunctor_t)(CallbackType_t aCBType, void* aAdr);
typedef void* (*DynDataPCallback_t)(void* aAdr);

// ---------------------------------------
// 8 bit value descriptors and containers
// ---------------------------------------

typedef struct {
    uint8_t*           m_dataP;
} U8ValP_t;

typedef struct {
    int8_t*            m_dataP;
} S8ValP_t;

typedef struct {
    uint8_t            m_min;
    uint8_t            m_max;
    void*              m_dataP;
} U8MMValP_t;

typedef struct {
    int8_t             m_min;
    int8_t             m_max;
    void*              m_dataP;
} S8MMValP_t;

typedef struct {
    uint8_t            m_scale;
    uint8_t            m_min;
    uint8_t            m_max;
    uint8_t            m_val;
} U8MMSVal_t;

typedef struct {
    uint8_t            m_scale;
    int8_t             m_min;
    int8_t             m_max;
    int8_t             m_val;
} S8MMSVal_t;

typedef struct {
    uint8_t            m_scale;
    uint8_t            m_min;
    uint8_t            m_max;
    void*              m_dataP;
} U8MMSValP_t;

typedef struct {
    uint8_t            m_scale;
    int8_t             m_min;
    int8_t             m_max;
    void*              m_dataP;
} S8MMSValP_t;

typedef struct {
    uint8_t            m_scale;
    uint8_t            m_min;
    uint8_t            m_max;
    void*              m_dataP;
    CallbackFunctor_t  m_callback;
} U8MMSValPCb_t;

typedef struct {
    uint8_t            m_scale;
    int8_t             m_min;
    int8_t             m_max;
    void*              m_dataP;
    CallbackFunctor_t  m_callback;
} S8MMSValPCb_t;

// a dynamic pointer to eeprom adress, resolved by callback
typedef struct {
    uint8_t            m_min;
    uint8_t            m_max;
    uint8_t*           m_dynDataInfo;
    DynDataPCallback_t m_callback;
} U8MMValDP_t;

typedef struct {
    int8_t             m_min;
    int8_t             m_max;
    uint8_t*           m_dynDataInfo;
    DynDataPCallback_t m_callback;
} S8MMValDP_t;

typedef struct { 
    uint8_t            m_min;
    uint8_t            m_max;
    void*              m_dataP;
    CallbackFunctor_t  m_callback;
} U8MMValPCb_t;

typedef struct { 
    int8_t             m_min;
    int8_t             m_max;
    void*              m_dataP;
    CallbackFunctor_t  m_callback;
} S8MMValPCb_t;

// ---------------------------------------
// 16 bit value descriptors and containers
// ---------------------------------------

typedef struct {
    uint16_t*          m_dataP;
} U16ValP_t;

typedef struct {
    int16_t*           m_dataP;
} S16ValP_t;

typedef struct {
    uint16_t           m_min;
    uint16_t           m_max;
    void*              m_dataP;
} U16MMValP_t;

typedef struct {
    int16_t            m_min;
    int16_t            m_max;
    void*              m_dataP;
} S16MMValP_t;

typedef struct {
    uint16_t           m_min;
    uint16_t           m_max;
    void*              m_dataP;
    CallbackFunctor_t  m_callback;
} U16MMValPCb_t;

typedef struct {
    int16_t            m_min;
    int16_t            m_max;
    void*              m_dataP;
    CallbackFunctor_t  m_callback;
} S16MMValPCb_t;

typedef struct {
    uint8_t            m_scale;
    uint16_t           m_min;
    uint16_t           m_max;
    void*              m_dataP;
} U16MMSValP_t;

typedef struct {
    uint8_t            m_scale;
    int16_t            m_min;
    int16_t            m_max;
    void*              m_dataP;
} S16MMSValP_t;

// a dynamic pointer to eeprom adress, resolved by callback
typedef struct {
    uint16_t            m_min;
    uint16_t            m_max;
    uint16_t*           m_dynDataInfo;
    DynDataPCallback_t m_callback;
} U16MMValDP_t;

typedef struct {
    int16_t             m_min;
    int16_t             m_max;
    uint16_t*           m_dynDataInfo;
    DynDataPCallback_t m_callback;
} S16MMValDP_t;

typedef struct {
    uint8_t            m_scale;
    uint16_t           m_min;
    uint16_t           m_max;
    void*              m_dataP;
    CallbackFunctor_t  m_callback;
} U16MMSValPCb_t;

typedef struct {
    uint8_t            m_scale;
    int16_t            m_min;
    int16_t            m_max;
    void*              m_dataP;
    CallbackFunctor_t  m_callback;
} S16MMSValPCb_t;

// ---------------------------------------
// 32 bit value descriptors and containers
// ---------------------------------------

typedef struct {
    uint8_t            m_scale;
    int32_t            m_min;
    int32_t            m_max;
    int32_t            m_val;
} S32MMSVal_t;

// this is the sctruct which is passed to EditNumber
typedef struct {
    uint8_t            m_scale;
    int32_t            m_min;
    int32_t            m_max;
    int32_t            m_val;
    CallbackFunctor_t  m_callback;
} S32MMSValCb_t;


typedef struct {
    uint8_t            m_scale;
    int32_t            m_min;
    int32_t            m_max;
    int32_t            m_val;
    void*              m_dataP;
} S32MMSValDP_t;

typedef struct {
    uint8_t            m_scale;
    int32_t            m_min;
    int32_t            m_max;
    int32_t            m_val;
    void*              m_dataP;
    CallbackFunctor_t  m_callback;
} S32MMSValDPCb_t;


// ---------------------------------------
// text value descriptors and containers
// ---------------------------------------

// #define EMBEDARRAY(a, ...) .m_texts = a, .m_moreTexts = { __VA_ARGS__ } 

typedef struct
{
    uint8_t            m_entryCount;
    uint8_t*           m_idxP;              // points to index to the text entry
    const char*        m_texts[];
} ITextListP_t;

typedef struct
{
    uint8_t            m_entryCount;
    uint8_t*           m_dynDataInfo;       // relative address for m_callback
    DynDataPCallback_t m_callback;
    const char*        m_texts[];
} ITextListDP_t;

typedef struct
{
    uint8_t            m_entryCount;
    uint8_t            m_idx;               // contains the index itself
    const char* const* m_textP;             // where the text-pointers start
} ITextListIdx_t;


typedef union
{
    uint8_t            m_u8Val;
    uint16_t           m_u16Val;
} IntValueUnion_t;

typedef union {
    S8ValP_t           m_s8ValP;
    S8MMValP_t         m_s8MMValP;
    S8MMValPCb_t       m_s8MMValPCb;
    S8MMValDP_t        m_s8MMValDP;
    S8MMSVal_t         m_s8MMSVal;
    S8MMSValP_t        m_s8MMSValP;
    S8MMSValPCb_t      m_s8MMSValPCb;

    U8ValP_t           m_u8ValP;
    U8MMValP_t         m_u8MMValP;
    U8MMValPCb_t       m_u8MMValPCb;
    U8MMValDP_t        m_u8MMValDP;
    U8MMSVal_t         m_u8MMSVal;
    U8MMSValP_t        m_u8MMSValP;
    U8MMSValPCb_t      m_u8MMSValPCb;

    U16ValP_t          m_u16ValP;
    U16MMValP_t        m_u16MMValP;
    U16MMValPCb_t      m_u16MMValPCb;
    U16MMValDP_t       m_u16MMValDP;
    U16MMSValP_t       m_u16MMSValP;
    U16MMSValPCb_t     m_u16MMSValPCb;

    S16ValP_t          m_s16ValP;
    S16MMValP_t        m_s16MMValP;
    S16MMValPCb_t      m_s16MMValPCb;
    S16MMValDP_t       m_s16MMValDP;
    S16MMSValP_t       m_s16MMSValP;
    S16MMSValPCb_t     m_s16MMSValPCb;

    S32MMSVal_t        m_s32MMSVal;
    S32MMSValDP_t      m_s32MMSValDP;
    S32MMSValDPCb_t    m_s32MMSValDPCb;
} ValueUnion_t;


// The following code courtesy of: stu_san on AVR Freaks

typedef struct
{
    unsigned int bit0:1;
    unsigned int bit1:1;
    unsigned int bit2:1;
    unsigned int bit3:1;
    unsigned int bit4:1;
    unsigned int bit5:1;
    unsigned int bit6:1;
    unsigned int bit7:1;
} _io_reg; 

#define REGISTER_BIT(rg,bt) ((volatile _io_reg*)&rg)->bit##bt
uint16_t pgm2ram(void *aTgt, const void* aSrc, size_t aLen);
uint16_t getBitCodedNumber(const unsigned char* bitCode, uint8_t idx, uint8_t bits);
void     rescale(uint8_t aScale, char *aBuf);
void     setIcons(IconType_t aType, uint8_t aMask);

#endif
