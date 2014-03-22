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
 * @file           EditNumber.c
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
#include "emx/Config.h"
#include "emx/Types.h"
#include "emx/Buttons.h"
#include "emx/Fonts.h"
#include "emx/Lcd.h"
#include "emx/Menu.h"

#include <stdlib.h>
#include <stdint.h>

uint8_t editNumber(S32MMSValCb_t* s32, uint8_t aY)
{
    // aY is the current yPos from were the edit was triggered
    /**
     * calculate the rectangle height on the display: 
     *    fontheight + 1 pix on top + 1 pix at bottom + 2*2 pix for the frame 
     */
    int32_t valBackup = s32->m_val; // backup the old value
    uint8_t fontHeight = FONTHEIGHT(EDITFONT);
    // re-use aY
    aY = (aY < LCDHEIGHT/2 - 9 ? aY+11: aY - 25);

    // maximum size, for a scaled long: "-2123456.789" + 1 leading blank + 0x00 = 14
    char valBuf[14]; 
    // put this in a block to release memory after calculation
    { 
        // get the biggest absolute value to calculate longest
        // possible string
        uint32_t min = (s32->m_min < 0) ? -s32->m_min : s32->m_min;
        uint32_t max = (s32->m_max < 0) ? -s32->m_max : s32->m_max;
        valBuf[0] = ' '; // leading blank
        valBuf[1] = '-'; // prepend minus-sign
        valBuf[2] = '.'; // prepend decimal point
        ltoa( (max > min ? max : min), valBuf+2, 10);
        //        maxDigits = strlen(valBuf+2);
    }

    uint8_t textLength = lcdBufPuts(AT_RAM, valBuf, &EDITFONT, 0, 0, LA_CHARWIDTHONLY); 
    
    uint8_t x = (LCDWIDTH - textLength - 8) / 2;     
    drawEditFrame(x, aY, textLength, fontHeight);
    x += 4;
    aY += 4;
    uint8_t endX = x + textLength;
    uint8_t clearLength = textLength;
    uint8_t key = 0;
    uint8_t accel = 1;
    int32_t step = 1;

    CallbackFunctor_t cb = s32->m_callback;

    // call the callback if exists
    if (cb)
        cb(CT_ENTRY, s32); 

    do
    {
        /** 
         * procedure: - clear rectangle
         *              write value to string
         *              length = (write string to ldcBuffer, width_only)
         *              clear area of (width x length)
         *              paint rectangle
         *              write string to lcdbuffer(last digit inverse)
         *              display buffer
         *              read key
         *                if (enter) update & return
         *                if (back) return
         *                if (accel) inc-value <<= 2;
         *                   else inc-value = 1; 
         *                if (up) increase
         *                if (down) decrease
         */
        
        lcdBufFillRect(x, aY, clearLength, fontHeight+1, COL_WHITE);
        // write current value
        ltoa(s32->m_val, valBuf, 10);

        if (s32->m_scale)
            rescale(s32->m_scale, valBuf);

        // get size in pixels
        textLength = lcdBufPuts(AT_RAM, valBuf, &EDITFONT, 0, 0, LA_CHARWIDTHONLY);
        uint8_t xt = endX - textLength;

        lcdBufPuts(AT_RAM, valBuf, &EDITFONT, xt, aY, COL_BLACK);
        //        lcdBufPuts(AT_RAM, valBuf, &EDITFONT, endX - textLength, aY, COL_BLACK);

        uint8_t iconMask = BT_BACK|BT_ENTER;
        if (s32->m_val > s32->m_min) 
            iconMask |= BT_MINUS;
        if (s32->m_val < s32->m_max) 
            iconMask |= BT_PLUS;

        setIcons(IT_EDIT, iconMask);
        lcdUpdate(1);

        key = pollButtons(BT_ALL, BF_ACCEL|BF_DELAY); 

        if (key & BF_ACCEL)
        {
            if (accel == 10)
            {
                accel = 1;
                if (step < (s32->m_max/8))
                    step *= 8;
            }
            else
                ++accel;
        }
        else
        {
            accel = 1;
            step = 1;
        }

        switch (key & 0xF0) // clean code
        {
            case BT_BACK: 
            case BT_ENTER:
                break;

            case BT_PLUS: 
                s32->m_val += step;
                if (s32->m_val > s32->m_max)
                    s32->m_val = s32->m_max;
                break;
            case BT_MINUS: 
                s32->m_val -= step; 
                if (s32->m_val < s32->m_min)
                    s32->m_val = s32->m_min;
                break;
        } // switch key
        
        // call the callback if exists
        if (cb)
            cb((CT_CHANGE | (key & 0xF0)), s32); 
    } while (! (key & (BT_BACK | BT_ENTER)) );

    if (key & BT_BACK) // restore old value if BT_BACK was pressed
        s32->m_val = valBackup;
    if (cb)
        cb((CT_RETURN | (key & 0xF0)), s32);     
    return key & 0xF0; // return pure key
} // editNumber (s32 ..)
