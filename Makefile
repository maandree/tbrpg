# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.
# 
# [GNU All Permissive License]


CPPFLAGS=
CXXFLAGS=-g -pedantic -W{all,extra} -O3
LDFLAGS=

PREFIX=/usr
GAMEDIR=/bin



all:
	[ -d bin ] || mkdir bin
	g++ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o bin/tbrpg src/program.cc


run: all
	bin/tbrpg



install:
	@echo Not implemented

uninstall:
	@echo Not implemented



clean:
	find ./ | grep \\.a\$$ | xargs rm
	find ./ | grep \\.o\$$ | xargs rm
	find ./ | grep \\.out\$$ | xargs rm

clean-gch:
	find ./ | grep \\.gch\$$ | xargs rm



.PHONY: clean clean-gch install uninstall

