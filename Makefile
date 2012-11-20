# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.
# 
# [GNU All Permissive License]


CPPFLAGS=
CXXFLAGS=-g --std=c++11 -pedantic -W{all,extra} -O3
LDFLAGS=


LEAKS=full
LOST=yes
RESOLUTION=high
REACHABLE=yes
UNDEF=yes
ORIGINS=yes
PARTIAL_OK=no
X_MEMCHECK=
USE_MEMCHECK=1

CACHE=yes
BRANCH=yes
X_CACHEGRIND=
USE_CACHEGRIND=0

X_CALLGRIND=
USE_CALLGRIND=0
X_HELGRIND=
USE_HELGRIND=0
X_DRD=
USE_DRD=0
X_MASSIF=
USE_MASSIF=0
X_SGCHECK=
USE_SGCHECK=0
X_LACKEY=
USE_LACKEY=0


PREFIX=/usr
GAMEDIR=/bin



all:
	[ -d bin ] || mkdir bin
	g++ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o bin/tbrpg src/*.{cc,hpp}



valgrind: valgrind-memcheck valgrind-cachegrind valgrind-callgrind valgrind-helgrind valgrind-drd \
	  valgrind-massif valgrind-sgcheck valgrind-lackey

valgrind-memcheck:
	[ $(USE_MEMCHECK) = 1 ] && \
	valgrind --tool=memcheck --leak-check=$(LEAKS) --show-possibly-lost=$(LOST) \
	         --leak-resolution=$(RESOLUTION) --show-reachable=$(REACHABLE)      \
	         --undef-value-errors=$(UNDEF) --track-origins=$(ORIGINS)           \
	         --partial-loads-ok=$(PARTIAL_OK) $(X_MEMCHECK) bin/tbrpg

valgrind-cachegrind:
	[ $(USE_CACHEGRIND) = 1 ] && \
	valgrind --tool=cachegrind --cache-sim=$(CACHE) --branch-sim=$(BRANCH) $(X_CACHEGRIND) bin/tbrpg

valgrind-callgrind:
	[ $(USE_CALLGRIND) = 1 ] && \
	valgrind --tool=callgrind $(X_CALLGRIND) bin/tbrpg

valgrind-helgrind:
	[ $(USE_HELGRIND) = 1 ] && \
	valgrind --tool=helgrind $(X_HELGRIND) bin/tbrpg

valgrind-drd:
	[ $(USE_DRD) = 1 ] && \
	valgrind --tool=drd $(X_DRD) bin/tbrpg

valgrind-massif:
	[ $(USE_MASSIF) = 1 ] && \
	valgrind --tool=massif $(X_MASSIF) bin/tbrpg

valgrind-sgcheck:
	[ $(USE_SGCHECK) = 1 ] && \
	valgrind --tool=sgcheck $(X_SGCHECK) bin/tbrpg

valgrind-lackey:
	[ $(USE_LACKEY) = 1 ] && \
	valgrind --tool=lackey $(X_LACKEY) bin/tbrpg


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



.PHONY: clean clean-gch install uninstall run valgrind valgrind-memcheck valgrind-cachegrind \
	valgrind-callgrind valgrind-helgrind valgrind-drd valgrind-massif valgrind-sgcheck \
	valgrind-lackey

