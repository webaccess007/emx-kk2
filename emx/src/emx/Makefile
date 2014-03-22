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
TARGET		 = emx
TARGETDIR        = ../../lib
SRC              = $(wildcard *.c)
ASRC		 = $(wildcard *.S)
INCLUDE          = -I../../include
EXTRA_LIBS       = 
EXTRACFLAGS      = -save-temps
EXTRACFLAGS     += -mcall-prologues
MCU		 = atmega324a
F_CPU		 = 20000000
DEFS             = -DDEBUG_CODE
OPT		 = s
CDEBUG           = -g

include ../../../$(COMPILER)-make_lib.rules

depend:
	if grep '^# DO NOT DELETE' $(MAKEFILE) >/dev/null; \
	then \
		sed -e '/^# DO NOT DELETE/,$$d' $(MAKEFILE) > \
			$(MAKEFILE).$$$$ && \
		$(MV) $(MAKEFILE).$$$$ $(MAKEFILE); \
	fi
	echo '# DO NOT DELETE THIS LINE -- make depend depends on it.' \
		>> $(MAKEFILE); \
	$(CC) -M -mmcu=$(MCU) $(CDEFS) $(CINCS) $(SRC) $(ASRC) >> $(MAKEFILE); \

# DO NOT DELETE THIS LINE -- make depend depends on it.
Debug.o: Debug.c ../../include/emx/Debug.h ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Fonts.h ../../include/emx/EmxFont.h \
 ../../include/emx/Lcd.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h \
 ../../include/emx/Buttons.h
DisplayITLDP.o: DisplayITLDP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Menu.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
DisplayITLP.o: DisplayITLP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Menu.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
DisplayMenu.o: DisplayMenu.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/EmxFont.h ../../include/emx/Fonts.h \
 ../../include/emx/Hardware.h ../../include/emx/Lcd.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h \
 ../../include/emx/Menu.h
DisplayMMDP.o: DisplayMMDP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Menu.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
DisplayMMP.o: DisplayMMP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Menu.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
DisplayMMPC.o: DisplayMMPC.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Menu.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
DisplayMMSP.o: DisplayMMSP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Menu.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
DisplayP.o: DisplayP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Menu.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
DisplayValue.o: DisplayValue.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 ../../include/emx/Lcd.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h \
 ../../include/emx/Fonts.h ../../include/emx/Feedback.h \
 ../../include/emx/Hardware.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
DrawEditFrame.o: DrawEditFrame.c ../../include/emx/Lcd.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
EditITLDP.o: EditITLDP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
EditITLP.o: EditITLP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
EditMMDP.o: EditMMDP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
EditMMP.o: EditMMP.c ../../include/emx/Config.h ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
EditMMPC.o: EditMMPC.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
EditMMSP.o: EditMMSP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
EditNumber.o: EditNumber.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/Fonts.h ../../include/emx/EmxFont.h \
 ../../include/emx/Lcd.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h \
 ../../include/emx/Menu.h
EditP.o: EditP.c ../../include/emx/Config.h ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
EditTextList.o: EditTextList.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/Fonts.h ../../include/emx/EmxFont.h \
 ../../include/emx/Lcd.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h \
 ../../include/emx/Menu.h
Feedback.o: Feedback.c ../../include/emx/Feedback.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/Hardware.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/util/delay.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/util/delay_basic.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/math.h
FontVerdana11.o: FontVerdana11.c ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h
FontVerdana19.o: FontVerdana19.c ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h
GetAttribs.o: GetAttribs.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/EmxFont.h
GetBitCodedNumber.o: GetBitCodedNumber.c ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h
GetCharBytes.o: GetCharBytes.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/EmxFont.h
GetCharFirstPix.o: GetCharFirstPix.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/EmxFont.h
GetCharOffset.o: GetCharOffset.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/EmxFont.h
GetCharWidth.o: GetCharWidth.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/EmxFont.h
GetValue.o: GetValue.c ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
LcdBufDrawrect.o: LcdBufDrawrect.c ../../include/emx/Lcd.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
LcdBuffer.o: LcdBuffer.c ../../include/emx/Lcd.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
LcdBufFillRect.o: LcdBufFillRect.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Lcd.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
LcdBufPutc.o: LcdBufPutc.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Lcd.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
LcdBufPuts.o: LcdBufPuts.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Lcd.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/util/delay.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/util/delay_basic.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/math.h
LcdBufSetPixel.o: LcdBufSetPixel.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Lcd.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
LcdBufWriteEmxLogo.o: LcdBufWriteEmxLogo.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Lcd.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
LcdInit.o: LcdInit.c ../../include/emx/Config.h ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Lcd.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h \
 ../../include/emx/Hardware.h ../../include/emx/Feedback.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/util/delay.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/util/delay_basic.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/math.h
LcdSend.o: LcdSend.c ../../include/emx/Config.h ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Hardware.h \
 ../../include/emx/Lcd.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
LcdSetContrast.o: LcdSetContrast.c ../../include/emx/Lcd.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
LcdUpdate.o: LcdUpdate.c ../../include/emx/Lcd.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
PgmToRam.o: PgmToRam.c \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h
PgmToRamITLDP.o: PgmToRamITLDP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Menu.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
PgmToRamITLP.o: PgmToRamITLP.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Menu.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
PgmToRamMMDP.o: PgmToRamMMDP.c ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
PgmToRamMMP.o: PgmToRamMMP.c ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
PgmToRamMMPC.o: PgmToRamMMPC.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Menu.h \
 ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
PgmToRamMMSP.o: PgmToRamMMSP.c ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
PgmToRamP.o: PgmToRamP.c ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/Menu.h ../../include/emx/EmxFont.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h
PollButtons.o: PollButtons.c ../../include/emx/Buttons.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/Feedback.h ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h ../../include/emx/Hardware.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/util/delay.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/util/delay_basic.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/math.h
PutValue.o: PutValue.c ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 ../../include/emx/Feedback.h ../../include/emx/Hardware.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/eeprom.h
Rescale.o: Rescale.c /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h
SetIcons.o: SetIcons.c ../../include/emx/Config.h \
 ../../include/emx/Types.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdlib.h \
 /usr/lib/gcc/avr/4.7.2/include/stddef.h \
 /usr/lib/gcc/avr/4.7.2/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/stdint.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/pgmspace.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/inttypes.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/io.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/sfr_defs.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iom324.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/iomxx4.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/portpins.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/common.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/version.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/fuse.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/avr/lock.h \
 ../../include/emx/Debug.h ../../include/emx/Buttons.h \
 ../../include/emx/Fonts.h ../../include/emx/EmxFont.h \
 ../../include/emx/Lcd.h \
 /usr/lib/gcc/avr/4.7.2/../../../avr/include/string.h \
 ../../include/emx/Menu.h
