# --------------------------------------------------------------------------
#                                  The "EMX"
#                          Embedded Mutable eXecutive
#                                  Framework
# 
#                   Copyright (C) 2014 Edgar (emax) Hermanns 
# --------------------------------------------------------------------------
# 
#  my $email = sprintf ("%s@%s.%s", "emax", "hermanns", "net");
# 
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
# 
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# 
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.

# 
# @file           Makefile
# @brief          Embedded Mutable eXecutive component
# @author         Edgar (emax) Hermanns
# @date           20140227
# @version        $Id$

# CHANGE LOG:
# ##  who  yyyymmdd   bug#  description
# --  ---  --------  -----  -------------------------------------------------
#  1  ...  ........  .....  ........
#  0  emx  20140227  -----  initial version
# 
# 
#                    
# set compiler to 'avr' or 'x86' to include the correct rules-file

COMPILER         = avr
TARGET		 = main
SRC              = $(wildcard *.c)
ASRC		 = $(wildcard *.S)
INCLUDE          = -I../../../emx/include
EXTRA_LIBS       = -L../../../emx/lib -lemx
MCU		 = atmega324a
F_CPU		 = 20000000
DEFS             = -DDEBUG_CODE
OPT		 = s
#CDEBUG          = -g
EXTRACFLAGS      = -save-temps

# optionally, set one of these: first is minimalistic, second is with float support
# PRINTF_LIB       = -Wl,-u,vfprintf -lprintf_min
# PRINTF_LIB       = -Wl,-u,vfprintf -lprintf_flt -lm

# optionally, set one of these, first is minimalistic, second is with float support
# SCANF_LIB        = -Wl,-u,vfscanf -lscanf_min
# SCANF_LIB        = -Wl,-u,vfscanf -lscanf_flt -lm

# optionally, set external memory options. 
# First is 64KB of ext RAM, starting after int.  RAM (ATmega128!), 
#          used for variables (.data/.bss) and heap (malloc()).
# Second is 64KB of ext RAM, starting after int.  RAM (ATmega128!), 
#          only used for heap (malloc()).
# EXTMEMOPTS = -Wl,-Tdata=0x801100,--defsym=__heap_end=0x80ffff
# EXTMEMOPTS = -Wl,--defsym=__heap_start=0x801100,--defsym=__heap_end=0x80ffff

# comment if not needed
# MATH_LIB	 = -lm

# optional eeprom programming
# AVRDUDE_WRITE_EEPROM  = -U eeprom:w:$(TARGET).eep

# Uncomment the following if you want avrdude's erase cycle counter.
# Note that this counter needs to be initialized first using -Yn,
# see avrdude manual.
# AVRDUDE_ERASE_COUNTER = -y

# Uncomment the following if you do /not/ wish a verification to be
# performed after programming the device.
# AVRDUDE_NO_VERIFY     = -V

# Increase verbosity level.  Please use this when submitting bug
# reports about avrdude. See <http://savannah.nongnu.org/projects/avrdude> 
# to submit bug reports.
# AVRDUDE_VERBOSE       = -v -v

include ../../../$(COMPILER)-make_pgm.rules

depend:
	if grep '^# DO NOT DELETE' $(MAKEFILE) >/dev/null; \
	then \
		sed -e '/^# DO NOT DELETE/,$$d' $(MAKEFILE) > \
			$(MAKEFILE).$$$$ && \
		$(MV) $(MAKEFILE).$$$$ $(MAKEFILE); \
	fi
	echo '# DO NOT DELETE THIS LINE -- make depend depends on it.' \
		>> $(MAKEFILE); \
	$(CC) -MM -mmcu=$(MCU) $(CDEFS) $(CINCS) $(SRC) $(ASRC) >> $(MAKEFILE); \

# DO NOT DELETE THIS LINE -- make depend depends on it.
main.o: main.c ../../../emx/include/emx/Fonts.h \
 ../../../emx/include/emx/EmxFont.h ../../../emx/include/emx/Lcd.h \
 ../../../emx/include/emx/Types.h ../../../emx/include/emx/Menu.h \
 ../../../emx/include/emx/Buttons.h
