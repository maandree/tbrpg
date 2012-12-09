# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.
# 
# [GNU All Permissive License]

SHELL=bash

NODES=3
OPTIMISE=-O0
all: OPTIMISE = -O3
CPPFLAGS=-DDEBUG
CXXFLAGS=$(OPTIMISE) -g --std=gnu++11 -pedantic -W{all,extra} -iquotedir=src/
LDFLAGS=

EXEC=bin/tbrpg
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

SOURCE :=
SOURCE += $(shell find src | grep \\.cc\$$  | sort)
SOURCE += $(shell find src | grep \\.c\$$   | sort)
SOURCE += $(shell find src | grep \\.h\$$   | sort)
SOURCE += $(shell find src | grep \\.hpp\$$ | sort)

TEST :=
TEST += $(shell find test | grep \\.cc\$$   | sort)
TEST += $(shell find test | grep \\.c\$$    | sort)
TEST += $(shell find test | grep \\.h\$$    | sort)
TEST += $(shell find test | grep \\.hpp\$$  | sort)
TEST += $(shell find test | grep \\.text\$$ | sort)

OBJS := $(shell (diff                                                                                                             \
	<(      find  src | grep -v '~$$'                     | grep '\.c' | sed -e 's/\.c$$//g' | sed -e 's/\.cc$$//g'  | sort)  \
	<(diff <(find src | grep -v '~$$'                     | grep '\.c' | sed -e 's/\.c$$//g' | sed -e 's/\.cc$$//g'  | sort)  \
	       <(find src | grep -v '~$$' | grep -v '\.gch$$' | grep '\.h' | sed -e 's/\.h$$//g' | sed -e 's/\.hpp$$//g' | sort)  \
	       | sed -e 's/>/</g' | grep '^< ' | sed -e 's/< //g' | sort)                                                         \
	| grep '^< ' | sed -e 's/^< //g' | sed -e 's/^src\///g' -e 's/$$/\.o/g') || echo -n)

GCHS :=
GCHS += $(shell find src | grep '\.hpp$$' | sort | sed -e 's/$$/\.gch/g')
GCHS += $(shell find src | grep '\.h$$'   | sort | sed -e 's/$$/\.gch/g')



## BUILD BINARIES ##

# DEFAULT
all: parallel tests info pdf
.PHONY: all


all-at-once: $(SOURCE)
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $(EXEC) $^

%.o src/%.hpp.gch: src/%.cc src/%.hpp
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@if [ ! -e /dev/shm/tbrpg ]; then  mkdir /dev/shm/tbrpg;  fi
	@if [ ! -L "src/$*.hpp.gch" ]; then                                  \
	     if [ -e "src/$*.hpp.gch" ]; then  $(RM) "src/$*.hpp.gch";  fi;  \
	     ln -s "/dev/shm/tbrpg/$*.hpp.gch" "src/$*.hpp.gch";             \
	 fi
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -c $^

%.o: src/%.cc
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -c $^

src/%.hpp.gch: src/%.hpp
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@if [ ! -e /dev/shm/tbrpg ]; then  mkdir /dev/shm/tbrpg;  fi
	@if [ ! -L "$@" ]; then                       \
	     if [ -e "$@" ]; then  $(RM) "$@";  fi;   \
	     ln -s "/dev/shm/tbrpg/$*.hpp.gch" "$@";  \
	 fi
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -c $^

%.o src/%.h.gch: src/%.c src/%.h
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@if [ ! -e /dev/shm/tbrpg ]; then  mkdir /dev/shm/tbrpg;  fi
	@if [ ! -L "src/$*.h.gch" ]; then                                \
	     if [ -e "src/$*.h.gch" ]; then  $(RM) "src/$*.h.gch";  fi;  \
	     ln -s "/dev/shm/tbrpg/$*.h.gch" "src/$*.h.gch";             \
	 fi
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -c $^

%.o: src/%.c
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -c $^

src/%.h.gch: src/%.h
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@if [ ! -e /dev/shm/tbrpg ]; then  mkdir /dev/shm/tbrpg;  fi
	@if [ ! -L "$@" ]; then                      \
	     if [ -e "$@" ]; then  $(RM) "$@";  fi;  \
	     ln -s "/dev/shm/tbrpg/$*.h.gch" "$@";   \
	 fi
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -c $^

$(EXEC) program: src/program.cc $(OBJS)
	@echo -e "\e[01;35m$(EXEC)\e[0m";
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $(EXEC) $^

program.sa: src/program.cc
	@echo -e "\e[01;35m$(EXEC)\e[0m";
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $(EXEC) $^ $(OBJS)

test/%: test/%.cc $(OBJS)
	@echo -e "\e[01;34m$@\e[0m";
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

test/%.sa: test/%.cc
	@echo -e "\e[01;34mtest/$*\e[0m";
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o test/$* $^ $(OBJS)

.PHONY: tests
tests:
	@ls -1 --color=no test | grep '\.cc$$' | sed -e 's/\.cc$$//g' |  \
	while read test; do                                              \
	    make test/"$$test";                                          \
	done

.PHONY: parallel
parallel: parallel.o program
parallel.o:
	@if [ ! -d  bin ]; then  mkdir bin;  fi
	@if [   -f .tmp ]; then  rm   .tmp;  fi
	@((time ((echo $(NODES) ; cat compiledependencies __order) |                                        \
	        (tools/paramake.py OPTIMISE=$(OPTIMISE) ; echo $$? > .tmp))) |&                             \
	sed -e 's/$$/\x1b\[0m/g' -e 's/^real\x09/\x1b\[2mreal\x09/g'                                        \
	-e 's/^user\x09/\x1b\[2muser\x09/g' -e 's/^sys\x09/\x1b\[2msys\x09/g'                               \
	-e 's/^make\[1\]: Entering directory /\x1b\[2mmake\[1\]: Entering directory /g'                     \
	-e 's/^make\[1\]: Leaving directory /\x1b\[2mmake\[1\]: Leaving directory /g') ; exit $$(cat .tmp)

.PHONY: sequencial
sequencial: sequencial.o program
sequencial.o:
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@cat compiledependencies __order | sort | uniq | tsort | tac > .tmp1
	@ls -1 --color=no src/ | grep \\.hpp\$ | sed -e s/\\.hpp\$//g | sort > .tmp
	@$(SHELL) -c 'diff <(sort < .tmp1 | uniq) .tmp > .tmp2 || echo -n'
	@((grep '> ' < .tmp2 | sed -e 's/> //g') ; cat .tmp1) > .tmp
	@time (count=$$(cat .tmp | wc -l);                                   \
	index=0;                                                             \
	cat .tmp | while read file; do                                       \
	    index=$$(( $$index + 1 ));                                       \
	    echo -e '\033[01;34m'$$file' ('$$index'/'$$count')\033[21;39m';  \
	    make OPTIMISE=$(OPTIMISE) $$file.o || exit 100;                  \
	done)



## GENERATE CODE ##

.PHONY: regen
regen:
	[ "$$(git branch | grep \*)" = "* variables" ]
	@cd src; ../tools/vargen.py < ../doc/variables 2> ../__order



## MAKE DOCUMENTATION ##

info: $(BOOK).info.gz
%.info: $(BOOKDIR)%.texinfo
	$(MAKEINFO) $^
%.info.gz: %.info #implies $(RM) $^
	gzip -9c < $^ > $@


pdf: $(BOOK).pdf
%.pdf: $(BOOKDIR)%.texinfo 
	texi2pdf $^
	make clean-tex clean.bak

pdf.gz: $(BOOK).pdf.gz
%.pdf.gz: %.pdf
	gzip -9c < $^ > $@

pdf.xz: $(BOOK).pdf.xz
%.pdf.xz: %.pdf
	xz -e9 < $^ > $@


dvi: $(BOOK).dvi
%.dvi: $(BOOKDIR)%.texinfo 
	$(TEXI2DVI) $^
	make clean-tex clean.bak

dvi.gz: $(BOOK).dvi.gz
%.dvi.gz: %.dvi
	gzip -9c < $^ > $@

dvi.xz: $(BOOK).dvi.xz
%.dvi.xz: %.dvi
	xz -e9 < $^ > $@



## INSTALLING AND UNINSTALLING ##

.PHONY: install
install:
	@echo Not implemented

.PHONY: install-bin
install-bin:
	@echo Not implemented

.PHONY: install-strip
install-strip:
	@echo Not implemented

.PHONY: install-html
install-html:
	@echo Not implemented

.PHONY: install-dvi
install-dvi:
	@echo Not implemented

.PHONY: install-ps
install-ps:
	@echo Not implemented

.PHONY: install-pdf
install-pdf:
	@echo Not implemented

.PHONY: installcheck
installcheck:
	@echo Not implemented

.PHONY: installdirs
installdirs:
	@echo Not implemented

.PHONY: uninstall
uninstall:
	@echo Not implemented



## MODIFY DOCUMENTATION ##

.PHONY: soft
soft: ; pdfjam --pagecolor 249,249,249 -o "$(BOOK).pdf" "$(BOOK).pdf"

.PHONY: softer
softer: ; pdfjam --pagecolor 249,246,240 -o "$(BOOK).pdf" "$(BOOK).pdf"

.PHONY: spell
spell: ; aspell --lang="$(LANG)" check "$(BOOKDIR)$(BOOK).texinfo"

.PHONY: grammar
grammar: ; link-parser < "$(BOOK)".texinfo 2>&1 | sed -e  \
	   s/'No complete linkages found'/'\x1b[1;31mNo complete linkage found\x1b[m'/g | less -r



## TESTING ##

.PHONY: run
run: $(EXEC) ; $(EXEC)

.PHONY: valgrind
valgrind: valgrind-memcheck valgrind-cachegrind valgrind-callgrind valgrind-helgrind valgrind-drd  \
	  valgrind-massif valgrind-sgcheck valgrind-lackey

.PHONY: valgrind-memcheck
valgrind-memcheck: $(EXEC)
	if [ $(USE_MEMCHECK) = 1 ]; then  \
	valgrind --tool=memcheck --leak-check=$(LEAKS) --show-possibly-lost=$(LOST)  \
	         --leak-resolution=$(RESOLUTION) --show-reachable=$(REACHABLE)       \
	         --undef-value-errors=$(UNDEF) --track-origins=$(ORIGINS)            \
	         --partial-loads-ok=$(PARTIAL_OK) $(X_MEMCHECK) $(EXEC); fi

.PHONY: valgrind-cachegrind
valgrind-cachegrind: $(EXEC)
	if [ $(USE_CACHEGRIND) = 1 ]; then  \
	valgrind --tool=cachegrind --cache-sim=$(CACHE) --branch-sim=$(BRANCH) $(X_CACHEGRIND) $(EXEC); fi

.PHONY: valgrind-callgrind
valgrind-callgrind: $(EXEC)
	if [ $(USE_CALLGRIND) = 1 ]; then  \
	valgrind --tool=callgrind $(X_CALLGRIND) $(EXEC); fi

.PHONY: valgrind-helgrind
valgrind-helgrind: $(EXEC)
	if [ $(USE_HELGRIND) = 1 ]; then  \
	valgrind --tool=helgrind $(X_HELGRIND) $(EXEC); fi

.PHONY: valgrind-drd
valgrind-drd: $(EXEC)
	if [ $(USE_DRD) = 1 ]; then  \
	valgrind --tool=drd $(X_DRD) $(EXEC); fi

.PHONY: valgrind-massif
valgrind-massif: $(EXEC)
	if [ $(USE_MASSIF) = 1 ]; then  \
	valgrind --tool=massif $(X_MASSIF) $(EXEC); fi

.PHONY: valgrind-sgcheck
valgrind-sgcheck: $(EXEC)
	if [ $(USE_SGCHECK) = 1 ]; then  \
	valgrind --tool=sgcheck $(X_SGCHECK) $(EXEC); fi

.PHONY: valgrind-lackey
valgrind-lackey: $(EXEC)
	if [ $(USE_LACKEY) = 1 ]; then  \
	valgrind --tool=lackey $(X_LACKEY) $(EXEC); fi



## CLEAN ##

.PHONY: maintainer-clean
maintainer-clean: clean

.PHONY: distclean realclean clobber
distclean: realclean
realclean: clobber
clobber: clean

.PHONY: mostlyclean
mostlyclean: clean.gz clean.xz clean.bak clean-doc clean-tex clean-doc

.PHONY: clean
clean: mostlyclean clean-bin

.PHONY: clean-bin
clean-bin: clean.a clean.o clean.gch clean.out
	@echo -e 'Cleaning \e[35mbin\e[m'
	@if [ -d "bin" ]; then  rm -r "bin";  fi
	@find ./test | grep -v \\.cc\$$ | grep -v \\.text\$$ | while read file; do  \
	    if [ -f "$$file" ]; then $(RM) "$$file"; fi                             \
	done

.PHONY: clean-tmp
clean-doc:
	@echo -e 'Cleaning \e[35mtmp\e[m'
	@if [ -f .tmp  ]; then  $(RM) .tmp ;  fi
	@if [ -f .tmp1 ]; then  $(RM) .tmp1;  fi
	@if [ -f .tmp2 ]; then  $(RM) .tmp2;  fi

.PHONY: clean-doc
clean-doc: clean.ps clean.pdf clean.dvi clean.info

.PHONY: clean-tex
clean-tex: clean.t2d clean.aux clean.cp clean.cps clean.fn clean.ky clean.log clean.pg  \
	   clean.pgs clean.toc clean.tp clean.vr clean.vrs clean.op clean.ops

.PHONY: clean.%
clean.%:
	@echo -e 'Cleaning \e[34m.$*\e[m'
	@find ./ | grep '\.$*$$' | grep -v '^./lab3.pdf$$' | while read file; do  \
	    if [ -f "$$file" ]; then $(RM)    "$$file"; fi;                       \
	    if [ -d "$$file" ]; then $(RM) -r "$$file"; fi;                       \
	done

.PHONY: clean/%
clean/%:
	@echo -e 'Cleaning \e[36m$*\e[m'
	@if [ -f     "$*.o"        ]; then  $(RM)     "$*.o"       ;  fi
	@if [ -f "src/$*.h.gch"    ]; then  $(RM) "src/$*.h.gch"   ;  fi
	@if [ -f "src/$*.hpp.gch"  ]; then  $(RM) "src/$*.hpp.gch" ;  fi
	@if [ -f "/dev/shm/tbrpg/$*.h.gch"    ]; then  $(RM) "/dev/shm/tbrpg/$*.h.gch"   ;  fi
	@if [ -f "/dev/shm/tbrpg/$*.hpp.gch"  ]; then  $(RM) "/dev/shm/tbrpg/$*.hpp.gch" ;  fi



## VIEW PDF DOCUMENT ##

.PHONY: view
view: $(BOOK).pdf
	if [ ! $$PDF_VIEWER = '' ]; then  \
	    $$PDF_VIEWER $^;              \
	else                              \
	    xpdf $^;                      \
	fi

.PHONY: atril
atril: $(BOOK).pdf ; atril $^

.PHONY: evince
evince: $(BOOK).pdf ; evince $^

.PHONY: xpdf
xpdf: $(BOOK).pdf ; xpdf $^

.PHONY: okular
okular: $(BOOK).pdf ; okular $^

.PHONY: gs
gs: $(BOOK).pdf ; gs $^

.PHONY: clean
jfbview: $(BOOK).pdf
	jfbview $^
	echo -en '\e[H\e[2J'



## OTHER STUFF ##

.PHONY: echo-src
echo-src:
	@echo "$(SOURCE)"

.PHONY: echo-test
echo-test:
	@echo "$(TEST)"

.PHONY: echo-obj
echo-obj:
	@echo "$(OBJS)"

.PHONY: echo-gch
echo-gch:
	@echo "$(GCHS)"

.PHONY: print
print: $(SOURCE)
	@for file in $?; do echo "$$file"; done

tar($(SOURCE) $(TEST)):
	@echo 'Not yet implemented'

tar.xz: tar
	@echo 'Not yet implemented'

shar($(SOURCE) $(TEST)):
	@echo 'Not yet implemented'

dist($(SOURCE) $(TEST)):
	@echo 'Not yet implemented'

.PHONY: test check
check: test
test:
	@echo 'Not yet implemented'

