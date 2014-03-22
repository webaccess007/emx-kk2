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
 * @file           Config.h
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
#ifndef CONFIG_H
#define CONFIG_H

#include "emx/Types.h"

#include <stdint.h>
#include <avr/pgmspace.h>

#ifdef DEBUG_CODE
extern unsigned char __heap_start;
#include "emx/Debug.h"
// debug RAM-address
# define DBR(a,b)   DebugHex(AT_RAM, a, &b, sizeof(b));
// debug RAM pointer, set size explicitly
# define DBRP(a,b,s)   DebugHex(AT_RAM, a, b, s);
// debug PGM-address
# define DBP(a,b)   DebugHex(AT_PGM, a, &b, sizeof(b));
// debug free ram
# define DBF(a)    { uint16_t __freeRam = SP - (uint16_t) &__heap_start; DBR(a, __freeRam); }
#else
# define DBR(a,b)  
# define DBRP(a, b, s)
# define DBP(a,b) 
# define DBF(a)
#endif

#endif
