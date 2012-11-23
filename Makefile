# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.
# 
# [GNU All Permissive License]

CPPFLAGS=
CXXFLAGS=-g --std=c++11 -pedantic -W{all,extra} -O3
LDFLAGS=

BOOK=tbrpg
BOOKDIR=doc/
LANG=en_GB-ise-w_accents-only

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



all: code info pdf



code:
	if [ ! -d bin ]; then  mkdir bin;  fi
	g++ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o bin/tbrpg src/*.{cc,hpp}



info:
	makeinfo "$(BOOKDIR)$(BOOK).texinfo"
	gzip -9 "$(BOOK).info"

pdf:
	texi2pdf "$(BOOKDIR)$(BOOK).texinfo"
	for ext in `echo aux cp cps fn ky log pg toc tp vr op ops pgs vrs`; do  \
		if [ -f "$(BOOK).$$ext" ]; then  rm "$(BOOK).$$ext";  fi        \
	done
	if [ -d "$(BOOK).t2d" ]; then  rm -r "$(BOOK).t2d";  fi

soft:
	pdfjam --pagecolor 249,249,249 -o "$(BOOK).pdf" "$(BOOK).pdf"

softer:
	pdfjam --pagecolor 249,246,240 -o "$(BOOK).pdf" "$(BOOK).pdf"

spell:
	aspell --lang="$(LANG)" check "$(BOOK).texinfo"

grammar:
	link-parser < "$(BOOK)".texinfo 2>&1 | sed -e  \
		s/'No complete linkages found'/'\x1b[1;31mNo complete linkage found\x1b[m'/g | less -r



valgrind: valgrind-memcheck valgrind-cachegrind valgrind-callgrind valgrind-helgrind valgrind-drd  \
	  valgrind-massif valgrind-sgcheck valgrind-lackey

valgrind-memcheck:
	if [ $(USE_MEMCHECK) = 1 ]; then  \
	valgrind --tool=memcheck --leak-check=$(LEAKS) --show-possibly-lost=$(LOST)  \
	         --leak-resolution=$(RESOLUTION) --show-reachable=$(REACHABLE)       \
	         --undef-value-errors=$(UNDEF) --track-origins=$(ORIGINS)            \
	         --partial-loads-ok=$(PARTIAL_OK) $(X_MEMCHECK) bin/tbrpg; fi

valgrind-cachegrind:
	if [ $(USE_CACHEGRIND) = 1 ]; then  \
	valgrind --tool=cachegrind --cache-sim=$(CACHE) --branch-sim=$(BRANCH) $(X_CACHEGRIND) bin/tbrpg; fi

valgrind-callgrind:
	if [ $(USE_CALLGRIND) = 1 ]; then  \
	valgrind --tool=callgrind $(X_CALLGRIND) bin/tbrpg; fi

valgrind-helgrind:
	if [ $(USE_HELGRIND) = 1 ]; then  \
	valgrind --tool=helgrind $(X_HELGRIND) bin/tbrpg; fi

valgrind-drd:
	if [ $(USE_DRD) = 1 ]; then  \
	valgrind --tool=drd $(X_DRD) bin/tbrpg; fi

valgrind-massif:
	if [ $(USE_MASSIF) = 1 ]; then  \
	valgrind --tool=massif $(X_MASSIF) bin/tbrpg; fi

valgrind-sgcheck:
	if [ $(USE_SGCHECK) = 1 ]; then  \
	valgrind --tool=sgcheck $(X_SGCHECK) bin/tbrpg; fi

valgrind-lackey:
	if [ $(USE_LACKEY) = 1 ]; then  \
	valgrind --tool=lackey $(X_LACKEY) bin/tbrpg; fi


run: code
	bin/tbrpg



install:
	@echo Not implemented

uninstall:
	@echo Not implemented


clean:
	find ./ | grep \\.a\$$    | while read file; do  rm "$$file";  done
	find ./ | grep \\.o\$$    | while read file; do  rm "$$file";  done
	find ./ | grep \\.out\$$  | while read file; do  rm "$$file";  done
	find ./ | grep \\.info\$$ | while read file; do  rm "$$file";  done
	find ./ | grep \\.gz\$$   | while read file; do  rm "$$file";  done
	for ext in `echo aux cp cps fn ky log pg toc tp vr bak op ops pgs vrs`; do  \
		if [ -f "$(BOOK).$$ext" ]; then  rm "$(BOOK).$$ext";  fi            \
	done
	if [ -d "$(BOOK).t2d" ]; then  rm -r "$(BOOK).t2d";  fi
	if [ -f "$(BOOK).texinfo.bak" ]; then  rm "$(BOOK).texinfo.bak";  fi

clean-gch:
	find ./ | grep \\.gch\$$ | while read file; do  rm "$$file";  done



view:
	if [ ! $$PDF_VIEWER = '' ]; then     \
		$$PDF_VIEWER "$(BOOK).pdf";  \
	else                                 \
		xpdf "$(BOOK).pdf";          \
	fi

atril:
	atril "$(BOOK).pdf"

evince:
	evince "$(BOOK).pdf"

xpdf:
	xpdf "$(BOOK).pdf"

okular:
	okular "$(BOOK).pdf"

gs:
	gs "$(BOOK).pdf"

jfbview:
	jfbview "$(BOOK).pdf"
	echo -en '\e[H\e[2J'



.PHONY: clean clean-gch install uninstall run valgrind valgrind-memcheck valgrind-cachegrind \
	valgrind-callgrind valgrind-helgrind valgrind-drd valgrind-massif valgrind-sgcheck \
	valgrind-lackey view atril evince xpdf okular gs jfbview all

