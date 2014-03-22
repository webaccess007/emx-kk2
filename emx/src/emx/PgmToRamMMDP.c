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
 * @file           PgmToRamMMDP.c
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
#include <emx/Types.h>
#include <emx/Menu.h>

#include <stdint.h>
#include <string.h>

void* pgmToRamMMDP(uint8_t aPType, PtrUnion_t* aPtrUnion, S32MMSValCb_t *aS32MMSValCb)
{
    // PtrUnion points o MMDP type
    ValueUnion_t u;
    memset(aS32MMSValCb, 0, sizeof(S32MMSValCb_t));

    // get adresses
    pgm2ram(&u, aPtrUnion, (IS8BIT(aPType) ? sizeof(S8MMValDP_t) : sizeof(S16MMValDP_t)));

    // set defaults
    DynDataPCallback_t getDFunc = (void*)     u.m_u8MMValDP.m_callback;
    void* dataInfo              = (void*)     u.m_u8MMValDP.m_dynDataInfo;

    if(IS8BIT(aPType))
    {
        if (ISSIGNED(aPType))
        {
            getDFunc            = u.m_s8MMValDP.m_callback;
            dataInfo            = u.m_s8MMValDP.m_dynDataInfo;
            aS32MMSValCb->m_min = u.m_s8MMValDP.m_min;
            aS32MMSValCb->m_max = u.m_s8MMValDP.m_max;
        }
        else
        {
            // getDFunc         = u.m_u8MMValDP.m_callback; // done be default initialization
            // dataInfo         = u.m_u8MMValDP.m_dynDataInfo; // done be default initialization
            aS32MMSValCb->m_min = u.m_u8MMValDP.m_min;
            aS32MMSValCb->m_max = u.m_u8MMValDP.m_max;
        }
    } // 8bit
    else if (IS16BIT(aPType))
    {
        if (ISSIGNED(aPType))
        {
            getDFunc            = u.m_s16MMValDP.m_callback;
            dataInfo            = u.m_s16MMValDP.m_dynDataInfo;
            aS32MMSValCb->m_min = u.m_s16MMValDP.m_min;
            aS32MMSValCb->m_max = u.m_s16MMValDP.m_max;
        }
        else
        {
            getDFunc            = u.m_u16MMValDP.m_callback;
            dataInfo            = u.m_u16MMValDP.m_dynDataInfo;
            aS32MMSValCb->m_min = u.m_u16MMValDP.m_min;
            aS32MMSValCb->m_max = u.m_u16MMValDP.m_max;
        }
    } // 16bit

    // get m_val
    void* dataP                 = (void*)   getDFunc(dataInfo);
    getValue(dataP, aPType, &aS32MMSValCb->m_val);
    return dataP;             
} // pgmToRamMMS
