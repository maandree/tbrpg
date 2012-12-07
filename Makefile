# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.
# 
# [GNU All Permissive License]

SHELL=bash

NODES=3
OPTIMISE=-O0
#OPTIMISE=-O3
CPPFLAGS=-DDEBUG
CXXFLAGS=$(OPTIMISE) -g --std=gnu++11 -pedantic -W{all,extra} -iquotedir=src/
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



all: parallel tests info pdf



code:
	if [ ! -d bin ]; then  mkdir bin;  fi
	time g++ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o bin/tbrpg src/*.{cc,hpp}

%.o: src/%.cc src/%.hpp
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@time g++ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -c src/$*.{cc,hpp}

%.o: src/%.hpp
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@time g++ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -c src/$*.hpp

%.o: src/%.c src/%.h
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@time g++ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -c src/$*.{c,h}

%.o: src/%.h
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@time g++ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -c src/$*.h

program: src/program.cc
	@if [ ! -d bin ]; then  mkdir bin;  fi
	time g++ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o bin/tbrpg src/program.cc *.o

test/%: test/%.cc
	time g++ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o test/$* test/$*.cc *.o

tests:
	ls -1 --color=no test | grep '\.cc$$' | sed -e 's/\.cc$$//g' |  \
	while read test; do                                             \
	    echo -e "\e[01;34mtest/$$test\e[0m";                        \
	    make test/"$$test";                                         \
	done

parallel:
	if [ ! -d bin ]; then  mkdir bin;  fi
	rm .tmp; \
	((time ((echo $(NODES) ; cat compiledependencies __order) | (tools/paramake.py ; echo $$? > .tmp))) |&  \
	sed -e 's/$$/\x1b\[0m/g' -e 's/^real\x09/\x1b\[2mreal\x09/g'                                            \
	-e 's/^user\x09/\x1b\[2muser\x09/g' -e 's/^sys\x09/\x1b\[2msys\x09/g'                                   \
	-e 's/^make\[1\]: Entering directory /\x1b\[2mmake\[1\]: Entering directory /g'                         \
	-e 's/^make\[1\]: Leaving directory /\x1b\[2mmake\[1\]: Leaving directory /g') ; exit $$(cat .tmp)
	make program

sequecial:
	if [ ! -d bin ]; then  mkdir bin;  fi
	cat compiledependencies __order | sort | uniq | tsort | tac > .tmp1
	ls -1 --color=no src/ | grep \\.hpp\$ | sed -e s/\\.hpp\$//g | sort > .tmp
	$(SHELL) -c 'diff <(sort < .tmp1 | uniq) .tmp > .tmp2 || echo -n'
	((grep '> ' < .tmp2 | sed -e 's/> //g') ; cat .tmp1) > .tmp
	time (count=$$(cat .tmp | wc -l);                                    \
	index=0;                                                             \
	cat .tmp | while read file; do                                       \
	    index=$$(( $$index + 1 ));                                       \
	    echo -e '\033[01;34m'$$file' ('$$index'/'$$count')\033[21;39m';  \
	    make $$file.o || exit 100;                                       \
	done)


regen:
	cd src; ../tools/vargen.py < ../doc/variables 2> ../__order


info:
	makeinfo "$(BOOKDIR)$(BOOK).texinfo"
	gzip -9f "$(BOOK).info"

pdf:
	texi2pdf "$(BOOKDIR)$(BOOK).texinfo"
	for ext in `echo aux cp cps fn ky log pg toc tp vr op ops pgs vrs`; do  \
	    if [ -f "$(BOOK).$$ext" ]; then  rm "$(BOOK).$$ext";  fi            \
	done
	if [ -d "$(BOOK).t2d" ]; then  rm -r "$(BOOK).t2d";  fi

soft:
	pdfjam --pagecolor 249,249,249 -o "$(BOOK).pdf" "$(BOOK).pdf"

softer:
	pdfjam --pagecolor 249,246,240 -o "$(BOOK).pdf" "$(BOOK).pdf"

spell:
	aspell --lang="$(LANG)" check "$(BOOKDIR)$(BOOK).texinfo"

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


run:
	bin/tbrpg



install:
	@echo Not implemented

uninstall:
	@echo Not implemented


clean: clean-gch
	if [ -d "bin" ]; then  rm -r "bin";  fi
	find ./     | grep    \\.a\$$    | while read file; do  rm "$$file";  done
	find ./     | grep    \\.o\$$    | while read file; do  rm "$$file";  done
	find ./     | grep    \\.out\$$  | while read file; do  rm "$$file";  done
	find ./     | grep    \\.info\$$ | while read file; do  rm "$$file";  done
	find ./     | grep    \\.gz\$$   | while read file; do  rm "$$file";  done
	find ./test | grep -v \\.cc\$$   | while read file; do  rm "$$file";  done
	if [ -f .tmp  ]; then  rm .tmp ;  fi
	if [ -f .tmp1 ]; then  rm .tmp1;  fi
	if [ -f .tmp2 ]; then  rm .tmp2;  fi
	for ext in `echo aux cp cps fn ky log pg toc tp vr bak op ops pgs vrs`; do  \
		if [ -f "$(BOOK).$$ext" ]; then  rm "$(BOOK).$$ext";  fi            \
	done
	if [ -d "$(BOOK).t2d" ]; then  rm -r "$(BOOK).t2d";  fi
	if [ -f "$(BOOK).texinfo.bak" ]; then  rm "$(BOOK).texinfo.bak";  fi
	if [ -f "$(BOOK).info" ]; then  rm "$(BOOK).info";  fi
	if [ -f "$(BOOK).info.gz" ]; then  rm "$(BOOK).info.gz";  fi

clean-gch:
	find ./ | grep \\.gch\$$ | while read file; do  rm "$$file";  done



view:
	if [ ! $$PDF_VIEWER = '' ]; then  \
	    $$PDF_VIEWER "$(BOOK).pdf";   \
	else                              \
	    xpdf "$(BOOK).pdf";           \
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
	valgrind-lackey view atril evince xpdf okular gs jfbview all regen parallel tests

