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
DIRS  =  emx/src/emx
DIRS +=  NGv4/lib/res  NGv4/lib NGv4/src 
DIRS +=  $(wildcard examples/*/src)
DIRS +=  $(wildcard tests/*/src)

SAVFILES  = emx/ NGv?/ avr-make_*rules Makefile Cheader.txt Mheader.txt flashKK.sh 
SAVFILES += addhdr.pl flashcount.txt readEeprom.sh writeEeprom.sh
SAVFILES += examples tests

TARDIRS   = emx examples

TARFILES  = avr-make_*rules Makefile Cheader.txt Mheader.txt flashKK.sh Doc/EMXmanualCurrent.pdf
TARFILES += addhdr.pl flashcount.txt readEeprom.sh writeEeprom.sh gpl.txt
# remember: the first target is always the default target

compile: 
	for i in $(DIRS); do make -C $$i; done

clean: 
	for i in $(DIRS); do make -C $$i clean; done

depend: 
	for i in $(DIRS); do make -C $$i depend; done

archive: clean depend
	tar cvzf Sav/saved$$(date +%Y%m%d_%H%M%S).tgz $(SAVFILES) 

tarball: clean depend
	for i in $(TARDIRS); \
	do \
	find $$i -name '*.c' | ./addhdr.pl Cheader.txt "Embedded Mutable eXecutive component"; \
	find $$i -name '*.h' | ./addhdr.pl Cheader.txt "Embedded Mutable eXecutive component"; \
	find $$i -iname 'makefile' | ./addhdr.pl Mheader.txt "Embedded Mutable eXecutive component"; \
	done ; \
	echo Makefile           | ./addhdr.pl Mheader.txt "Embedded Mutable eXecutive component"; \
	echo avr-make_lib.rules | ./addhdr.pl Mheader.txt "Embedded Mutable eXecutive component"; \
	echo avr-make_pgm.rules | ./addhdr.pl Mheader.txt "Embedded Mutable eXecutive component"; \
	tar cvzf /tmp/EMX$$(date +%Y%m%d_%H%M%S).tgz $(TARDIRS) $(TARFILES)

all: clean depend compile

help:
	@echo ;\
	echo "targets: compile (compile everything)"; \
	echo "         clean   (clean everything)"; \
	echo "         depend  (update makefiles with dependencies)"; \
	echo "         archive (archive everything to Sav/savedYYYYMMDD.tgz)"; \
	echo "         help    (this screen)" ;\
	echo
