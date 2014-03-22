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
 * @file           PgmToRamITLP.c
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
#include <emx/Config.h>
#include <emx/Types.h>
#include <emx/Menu.h>

#include <stdint.h>
#include <string.h>

void* pgmToRamITLP(uint8_t aPType, PtrUnion_t* aPtrUnion, ITextListIdx_t *aITextListIdx)
{
    // PtrUnion points o ITLP type
    ITextListP_t iTextListP;
    memset(aITextListIdx, 0, sizeof(ITextListIdx_t));

    const ITextListP_t *tp = (ITextListP_t*) aPtrUnion;
    pgm2ram(&iTextListP, aPtrUnion, sizeof(ITextListP_t));

    aITextListIdx->m_entryCount = iTextListP.m_entryCount;
    aITextListIdx->m_textP = tp->m_texts;

    int32_t i; 
    getValue(iTextListP.m_idxP, aPType, &i);    
    aITextListIdx->m_idx = i;
    return iTextListP.m_idxP;
} // pgmToRamITLP
