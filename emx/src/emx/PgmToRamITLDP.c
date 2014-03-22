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
 * @file           PgmToRamITLDP.c
 * @brief          Embedded Mutable eXecutive component
 * @author         Edgar (emax) Hermanns
 * @date           20140314
 * @version        $Id$
 *
 * CHANGE LOG:
 * ##  who  yyyymmdd   bug#  description
 * --  ---  --------  -----  -------------------------------------------------
 *  1  ...  ........  .....  ........
 *  0  emx  20140314  -----  initial version
 */
#include <emx/Config.h>
#include <emx/Types.h>
#include <emx/Menu.h>

#include <stdint.h>
#include <string.h>

void* pgmToRamITLDP(uint8_t aPType, PtrUnion_t* aPtrUnion, ITextListIdx_t *aITextListIdx)
{
    // PtrUnion points o ITLP type
    ITextListDP_t iTextListDP;
    memset(aITextListIdx, 0, sizeof(ITextListIdx_t));

    const ITextListDP_t *tp      = (ITextListDP_t*) aPtrUnion;
    pgm2ram(&iTextListDP, aPtrUnion, sizeof(ITextListDP_t));

    DynDataPCallback_t getDFunc  = (void*) iTextListDP.m_callback;
    void* dataInfo               = (void*) iTextListDP.m_dynDataInfo;
    void* dataP                  = (void*) getDFunc(dataInfo);

    aITextListIdx->m_entryCount  = iTextListDP.m_entryCount;
    aITextListIdx->m_textP       = tp->m_texts;

    int32_t i; 
    getValue(dataP, aPType, &i);    
    aITextListIdx->m_idx = i;
    return dataP;
} // pgmToRamITLP
