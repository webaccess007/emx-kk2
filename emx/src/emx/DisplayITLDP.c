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
 * @file           DisplayITLDP.c
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
#include "emx/Config.h"
#include "emx/Types.h"
#include "emx/Menu.h"

#include <avr/pgmspace.h>
#include <avr/eeprom.h>

#include <stdlib.h>
#include <stdint.h>

void displayITLDP(HandlerType_t aHandlerType, uint8_t aPType, PtrUnion_t* aPtrUnion,uint8_t aY, uint8_t aCol)
{
    // the value holder
    ITextListIdx_t   iTextListIdx;
    pgmToRamITLDP(aPType, aPtrUnion, &iTextListIdx);
    const char* buf = (char*) pgm_read_word(iTextListIdx.m_textP + iTextListIdx.m_idx);
    displayValue(AT_PGM, buf, aY, aCol);
} // editVar


