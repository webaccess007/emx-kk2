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
 * @file           Rescale.c
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
#include <stdint.h>

void rescale(uint8_t aScale, char *aBuf)
{
    /**
     * rescale a value in buf[] to correct output
     * e.g: buf = [1234], scale = 3, result = [1.234]
     */ 
    
    // NOTE: this function relies on a sufficient length of aBuf !!
    
    if (!aScale) 
        return;
    
    if (*aBuf == '-') // ignore the sign
        ++aBuf;

    // goto the end of buf
    char* src = aBuf;
    while (*src)
        ++src;

    // src now points to \0 (i.e. end-of-string)

    uint8_t len = src-aBuf;
    if (!len)
        return;
 
    /**
     * calulate new end-of-string:
     * end-of-string = aBuf + optinal[pre-comma-digits] + '.' + post-comma-digits
     */
    char* tgt = aBuf;

    if (aScale > len)
        tgt += aScale;
    else
        tgt += len;

    *(tgt+1) = 0;
    --src;
    do  // transfer frcational part as far as it exists   
    {    
        *tgt = *src;
        --src;
        --tgt;   
        --len;
        --aScale;
    } while(len && aScale);

    while (aScale) // fill up with zeros if necessary
    {
        *tgt = '0';
        --tgt;
        --aScale;
    }
    
    *tgt = '.'; // set decimal point
} // rescale
