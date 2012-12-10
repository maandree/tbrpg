# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.
# 
# [GNU All Permissive License]

SHELL=bash

NODES=3

VERSION := 0.999

all: OPTIMISE ?= -O3
OPTIMISE ?= -O0
CPPFLAGS ?= -DDEBUG
CXXFLAGS ?= $(OPTIMISE) -g --std=gnu++11 -pedantic -W{all,extra} -iquotedir=src/
LDFLAGS ?=

PROGRAM=tbrpg
EXEC=bin/$(PROGRAM)
BOOK=$(PROGRAM)
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

STRIP=
install-strip: STRIP = -s

DESTDIR=
prefix=/usr
gamedir=/game
datadir=/share/$(PROGRAM)
docdir=/doc/$(PROGRAM)

OS-KERNEL=$(shell uname --kernel-release | cut -d - -f 3)

ifeq ($(OS-KERNEL),ARCH)
  gamedir=/bin
  docdir=/share/doc/$(PROGRAM)
endif

TAGSFLAGS=
TAGSFLAGS_C=
TAGSFLAGS_H=
TAGSFLAGS_CC=
TAGSFLAGS_HPP=
TAGSFLAGS_PY=
TAGSFLAGS_JAVA=
TAGSFLAGS_PL=
TAGSFLAGS_SH=
TAGSFLAGS_MAKE=

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

MISC_FILES=compiledependencies COPYING LICENSE Makefile __order tools/paramake.py tools/vargen.py

AR_FILES=$(SOURCE) $(TEST) $(MISC_FILES)


## BUILD BINARIES ##

# DEFAULT
all: parallel tests info pdf
.PHONY: all


all-at-once: $(SOURCE)
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o "$(EXEC)" $^

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
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o "$(EXEC)" $^

program.sa: src/program.cc
	@echo -e "\e[01;35m$(EXEC)\e[0m";
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o "$(EXEC)" $^ $(OBJS)

test/%: test/%.cc $(OBJS)
	@echo -e "\e[01;34m$@\e[0m";
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o "$@" $^

test/%.sa: test/%.cc
	@echo -e "\e[01;34mtest/$*\e[0m";
	@time $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o test/"$*" $^ $(OBJS)

.PHONY: tests
tests:
	@ls -1 --color=no test | grep '\.cc$$' | sed -e 's/\.cc$$//g' |  \
	while read test; do                                              \
	    make test/"$$test";                                          \
	done

.PHONY: parallel
parallel: parallel. program
parallel.:
	@if [ ! -d  bin ]; then  mkdir bin;  fi
	@if [   -f .tmp ]; then  rm   .tmp;  fi
	@((time ((echo $(NODES) ; cat compiledependencies __order) |                                        \
	        (tools/paramake.py OPTIMISE="$(OPTIMISE)" CPPFLAGS="$(CPPFLAGS)" ; echo $$? > .tmp))) |&    \
	sed -e 's/$$/\x1b\[0m/g' -e 's/^real\x09/\x1b\[2mreal\x09/g'                                        \
	-e 's/^user\x09/\x1b\[2muser\x09/g' -e 's/^sys\x09/\x1b\[2msys\x09/g'                               \
	-e 's/^make\[1\]: Entering directory /\x1b\[2mmake\[1\]: Entering directory /g'                     \
	-e 's/^make\[1\]: Leaving directory /\x1b\[2mmake\[1\]: Leaving directory /g') ; exit $$(cat .tmp)

.PHONY: sequencial
sequencial: sequencial. program
sequencial.:
	@if [ ! -d bin ]; then  mkdir bin;  fi
	@cat compiledependencies __order | sort | uniq | tsort | tac > .tmp1
	@ls -1 --color=no src/ | grep \\.hpp\$ | sed -e s/\\.hpp\$//g | sort > .tmp
	@$(SHELL) -c 'diff <(sort < .tmp1 | uniq) .tmp > .tmp2 || echo -n'
	@((grep '> ' < .tmp2 | sed -e 's/> //g') ; cat .tmp1) > .tmp
	@time (count=$$(cat .tmp | wc -l);                                                            \
	index=0;                                                                                      \
	cat .tmp | while read file; do                                                                \
	    (( index++ ));                                                                            \
	    echo -e '\033[01;34m'"$$file"' ('$$index'/'$$count')\033[21;39m';                         \
	    if [ -f "src/$$file.c" ]; then                                                            \
	        make OPTIMISE="$(OPTIMISE)" CPPFLAGS="$(CPPFLAGS)" "$$file.o" || exit 100;            \
	    elif [ -f "src/$$file.cc" ]; then                                                         \
	        make OPTIMISE="$(OPTIMISE)" CPPFLAGS="$(CPPFLAGS)" "$$file.o" || exit 100;            \
	    elif [ -f "src/$$file.hpp" ]; then                                                        \
	        make OPTIMISE="$(OPTIMISE)" CPPFLAGS="$(CPPFLAGS)" "src/$$file.hpp.gch" || exit 100;  \
	    else                                                                                      \
	        make OPTIMISE="$(OPTIMISE)" CPPFLAGS="$(CPPFLAGS)" "src/$$file.h.gch" || exit 100;    \
	    fi;                                                                                       \
	done)



## GENERATE CODE ##

.PHONY: regen
regen:
	[ "$$(git branch | grep \*)" = "* variables" ]
	@cd src;  ("../tools/vargen.py" < "../doc/variables" 2> "../__order" ||  \
	           (ev=$$? ; echo "../__order" ; exit $$ev))



## MAKE DOCUMENTATION ##

info: $(BOOK).info.gz
%.info: $(BOOKDIR)%.texinfo
	$(MAKEINFO) "$<"
%.info.gz: %.info #implies $(RM) "$<"
	gzip -9c < "$<" > "$@"


pdf: $(BOOK).pdf
%.pdf: $(BOOKDIR)%.texinfo 
	texi2pdf "$<"
	make clean-tex clean.bak

pdf.gz: $(BOOK).pdf.gz
%.pdf.gz: %.pdf
	gzip -9c < "$<" > "$@"

pdf.xz: $(BOOK).pdf.xz
%.pdf.xz: %.pdf
	xz -e9 < "$<" > "$@"


dvi: $(BOOK).dvi
%.dvi: $(BOOKDIR)%.texinfo 
	$(TEXI2DVI) "$<"
	make clean-tex clean.bak

dvi.gz: $(BOOK).dvi.gz
%.dvi.gz: %.dvi
	gzip -9c < "$<" > "$@"

dvi.xz: $(BOOK).dvi.xz
%.dvi.xz: %.dvi
	xz -e9 < "$<" > "$@"



## INSTALLING AND UNINSTALLING ##

.PHONY: install
install: install-bin

.PHONY: install-bin
install-bin: $(EXEC) installdirs install-pdf.gz install-info
	install -m 755 $(STRIP) "$(EXEC)" "$(DESTDIR)$(prefix)$(gamedir)"

.PHONY: install-strip
install-strip: install-bin

.PHONY: install-html
install-html:
	@echo Not implemented  FIXME

.PHONY: install-info
install-info: $(BOOK).info
	@echo Not implemented  FIXME


.PHONY: install-dvi
install-dvi: $(BOOK).dvi
	install -m 644 "$<" "$(EXEC)" "$(DESTDIR)$(prefix)$(docdir)"

.PHONY: install-ps
install-ps: $(BOOK).ps
	install -m 644 "$^" "$(EXEC)" "$(DESTDIR)$(prefix)$(docdir)"

.PHONY: install-pdf
install-pdf: $(BOOK).pdf
	install -m 644 "$^" "$(EXEC)" "$(DESTDIR)$(prefix)$(docdir)"

.PHONY: install-dvi.gz
install-dvi.gz: $(BOOK).dvi.gz
	install -m 644 "$^" "$(EXEC)" "$(DESTDIR)$(prefix)$(docdir)"

.PHONY: install-ps.gz
install-ps.gz: $(BOOK).ps.gz
	install -m 644 "$^" "$(EXEC)" "$(DESTDIR)$(prefix)$(docdir)"

.PHONY: install-pdf.gz
install-pdf.gz: $(BOOK).pdf.gz
	install -m 644 "$^" "$(EXEC)" "$(DESTDIR)$(prefix)$(docdir)"

.PHONY: install-dvi.xz
install-dvi.xz: $(BOOK).dvi.xz
	install -m 644 "$^" "$(EXEC)" "$(DESTDIR)$(prefix)$(docdir)"

.PHONY: install-ps.xz
install-ps.xz: $(BOOK).ps.xz
	install -m 644 "$^" "$(EXEC)" "$(DESTDIR)$(prefix)$(docdir)"

.PHONY: install-pdf.xz
install-pdf.xz: $(BOOK).pdf.xz
	install -m 644 "$^" "$(EXEC)" "$(DESTDIR)$(prefix)$(docdir)"


.PHONY: uninstall
uninstall: uninstalldirs                                \
	uninstall/$(prefix)$(gamedir)/$(PROGRAM)        \
	uninstall/$(prefix)$(docdir)/$(PROGRAM).dvi     \
	uninstall/$(prefix)$(docdir)/$(PROGRAM).ps      \
	uninstall/$(prefix)$(docdir)/$(PROGRAM).pdf     \
	uninstall/$(prefix)$(docdir)/$(PROGRAM).dvi.gz  \
	uninstall/$(prefix)$(docdir)/$(PROGRAM).ps.gz   \
	uninstall/$(prefix)$(docdir)/$(PROGRAM).pdf.gz  \
	uninstall/$(prefix)$(docdir)/$(PROGRAM).dvi.xz  \
	uninstall/$(prefix)$(docdir)/$(PROGRAM).ps.xz   \
	uninstall/$(prefix)$(docdir)/$(PROGRAM).pdf.xz

uninstall/%:
	if [ -f "$*" ]; then  $(RM) "$(DESTDIR)$*";  fi

.PHONY: installdirs
installdirs:
	if [ ! "$(DESTDIR)" = "" ]; then  install -d "$(DESTDIR)";  fi
	install -d "$(DESTDIR)$(prefix)"
	install -d "$(DESTDIR)$(prefix)$(gamedir)"
	install -d "$(DESTDIR)$(prefix)$(docdir)"

.PHONY: uninstalldirs
uninstalldirs: uninstalldir/$(prefix)$(gamedir)  \
	       uninstalldir/$(prefix)$(docdir)

uninstalldir/%:
	if [ -d "$*" ]; then                        \
	  if [ $$(ls -A1 "$*" | wc -l) = 0 ]; then  \
	    rmdir "$*";  fi;  fi


.PHONY: installcheck
installcheck:
	@echo Not implemented


## MODIFY DOCUMENTATION ##

.PHONY: soft
soft: ; pdfjam --pagecolor 249,249,249 -o "$(BOOK).pdf" "$(BOOK).pdf"

.PHONY: softer
softer: ; pdfjam --pagecolor 249,246,240 -o "$(BOOK).pdf" "$(BOOK).pdf"

.PHONY: spell
spell: ; aspell --lang="$(LANG)" check "$(BOOKDIR)$(BOOK).texinfo"

.PHONY: grammar
grammar: ; link-parser < "$(BOOK).texinfo" 2>&1 | sed -e  \
	   s/'No complete linkages found'/'\x1b[1;31mNo complete linkage found\x1b[m'/g | less -r



## TESTING ##

.PHONY: run
run: $(EXEC) ; "$(EXEC)"

.PHONY: valgrind
valgrind: valgrind-memcheck valgrind-cachegrind valgrind-callgrind valgrind-helgrind valgrind-drd  \
	  valgrind-massif valgrind-sgcheck valgrind-lackey

.PHONY: valgrind-memcheck
valgrind-memcheck: $(EXEC)
	if [ $(USE_MEMCHECK) = 1 ]; then  \
	valgrind --tool=memcheck --leak-check=$(LEAKS) --show-possibly-lost=$(LOST)  \
	         --leak-resolution=$(RESOLUTION) --show-reachable=$(REACHABLE)       \
	         --undef-value-errors=$(UNDEF) --track-origins=$(ORIGINS)            \
	         --partial-loads-ok=$(PARTIAL_OK) $(X_MEMCHECK) "$(EXEC)";  fi

.PHONY: valgrind-cachegrind
valgrind-cachegrind: $(EXEC)
	if [ $(USE_CACHEGRIND) = 1 ]; then  \
	valgrind --tool=cachegrind --cache-sim=$(CACHE) --branch-sim=$(BRANCH) $(X_CACHEGRIND) "$(EXEC)";  fi

.PHONY: valgrind-callgrind
valgrind-callgrind: $(EXEC)
	if [ $(USE_CALLGRIND) = 1 ]; then  \
	valgrind --tool=callgrind $(X_CALLGRIND) "$(EXEC)";  fi

.PHONY: valgrind-helgrind
valgrind-helgrind: $(EXEC)
	if [ $(USE_HELGRIND) = 1 ]; then  \
	valgrind --tool=helgrind $(X_HELGRIND) "$(EXEC)";  fi

.PHONY: valgrind-drd
valgrind-drd: $(EXEC)
	if [ $(USE_DRD) = 1 ]; then  \
	valgrind --tool=drd $(X_DRD) "$(EXEC)";  fi

.PHONY: valgrind-massif
valgrind-massif: $(EXEC)
	if [ $(USE_MASSIF) = 1 ]; then  \
	valgrind --tool=massif $(X_MASSIF) "$(EXEC)";  fi

.PHONY: valgrind-sgcheck
valgrind-sgcheck: $(EXEC)
	if [ $(USE_SGCHECK) = 1 ]; then  \
	valgrind --tool=sgcheck $(X_SGCHECK) "$(EXEC)";  fi

.PHONY: valgrind-lackey
valgrind-lackey: $(EXEC)
	if [ $(USE_LACKEY) = 1 ]; then  \
	valgrind --tool=lackey $(X_LACKEY) "$(EXEC)";  fi



## CLEAN ##

.PHONY: maintainer-clean
maintainer-clean: clean

.PHONY: distclean realclean clobber
distclean: realclean
realclean: clobber
clobber: clean

.PHONY: mostlyclean
mostlyclean: clean-bak clean.bak clean-doc clean-tex clean-doc

.PHONY: clean
clean: mostlyclean clean-bin

.PHONY: clean-bak
clean-bak: clean.cpio clean.cpio.gz clean.cpio.xz clean.cpio.bz2  \
	   clean.shar clean.shar.gz clean.shar.xz clean.shar.bz2  \
	   clean.tar  clean.tar.gz  clean.tar.xz  clean.tar.bz2   \
	   clean.ar   clean.ar.gz   clean.ar.xz   clean.ar.bz2

.PHONY: clean-bin
clean-bin: clean.a clean.a.gz clean.a.xz clean.a.bz2 clean.o clean.gch clean.out
	@echo -e 'Cleaning \e[35mbin\e[m'
	@if [ -d "bin" ]; then  rm -r "bin";  fi
	@find ./test | grep -v '\.cc$$' | grep -v '\.text$$' | while read file; do  \
	    if [ -f "$$file" ];  then $(RM) "$$file";  fi                           \
	done

.PHONY: clean-tmp
clean-doc:
	@echo -e 'Cleaning \e[35mtmp\e[m'
	@if [ -f ".tmp"  ]; then  $(RM) ".tmp" ;  fi
	@if [ -f ".tmp1" ]; then  $(RM) ".tmp1";  fi
	@if [ -f ".tmp2" ]; then  $(RM) ".tmp2";  fi

.PHONY: clean-doc
clean-doc: clean.ps clean.pdf clean.dvi clean.info              \
	   clean.ps.gz clean.pdf.gz clean.dvi.gz clean.info.gz  \
	   clean.ps.xz clean.pdf.xz clean.dvi.xz clean.info.xz

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

.PHONY: clean.%.gz
clean.%.gz:
	@echo -e 'Cleaning \e[34m.$*.gz\e[m'
	@find ./ | grep '\.$*.gz$$' | while read file; do    \
	    if [ -f "$$file" ]; then $(RM)    "$$file"; fi;  \
	    if [ -d "$$file" ]; then $(RM) -r "$$file"; fi;  \
	done

.PHONY: clean.%.xz
clean.%.xz:
	@echo -e 'Cleaning \e[34m.$*.xz\e[m'
	@find ./ | grep '\.$*.xz$$' | while read file; do    \
	    if [ -f "$$file" ]; then $(RM)    "$$file"; fi;  \
	    if [ -d "$$file" ]; then $(RM) -r "$$file"; fi;  \
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
	if [ ! "$$PDF_VIEWER" = '' ]; then  \
	    "$$PDF_VIEWER" "$<";            \
	else                                \
	    xpdf "$<";                      \
	fi

.PHONY: atril
atril: $(BOOK).pdf ; atril "$<"

.PHONY: evince
evince: $(BOOK).pdf ; evince "$<"

.PHONY: xpdf
xpdf: $(BOOK).pdf ; xpdf "$<"

.PHONY: okular
okular: $(BOOK).pdf ; okular "$<"

.PHONY: gs
gs: $(BOOK).pdf ; gs "$<"

.PHONY: clean
jfbview: $(BOOK).pdf
	jfbview "$<"
	echo -en '\e[H\e[2J'



## OTHER STUFF ##

.PHONY: TAGS
TAGS:
	find ./ | grep    '\.c$$'      | xargs etags $(TAGSFLAGS) $(TAGSFLAGS_C)    --language=c
	find ./ | grep    '\.h$$'      | xargs etags $(TAGSFLAGS) $(TAGSFLAGS_H)    --language=c
	find ./ | grep    '\.cc$$'     | xargs etags $(TAGSFLAGS) $(TAGSFLAGS_CC)   --language=c++
	find ./ | grep    '\.hpp$$'    | xargs etags $(TAGSFLAGS) $(TAGSFLAGS_HPP)  --language=c++
	find ./ | grep    '\.py$$'     | xargs etags $(TAGSFLAGS) $(TAGSFLAGS_PY)   --language=python
	find ./ | grep    '\.jav$$'    | xargs etags $(TAGSFLAGS) $(TAGSFLAGS_JAVA) --language=java
	find ./ | grep    '\.java$$'   | xargs etags $(TAGSFLAGS) $(TAGSFLAGS_JAVA) --language=java
	find ./ | grep    '\.pl$$'     | xargs etags $(TAGSFLAGS) $(TAGSFLAGS_PL)   --language=perl
	find ./ | grep    '\.sh$$'     | xargs etags $(TAGSFLAGS) $(TAGSFLAGS_SH)   --language=shell-script
	find ./ | grep -i 'makefile$$' | xargs etags $(TAGSFLAGS) $(TAGSFLAGS_MAKE) --language=gnumakefile


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
	@for file in $?; do  echo "$$file";  done


ar: tbrpg.a($(OBJS))
tbrpg.a($(OBJS)):
	$(AR) rcs "$@" "$%"

.PHONY: tbrpg.tar
tar: tbrpg.tar
tbrpg.tar:
	tar -c $(AR_FILES) > "$@"

tar.gz: tbrpg.tar.gz
tbrpg.tar.gz: tbrpg.tar #implies $(RM) "$<"
	gz -9c < "$<" > "$@"

tar.xz: tbrpg.tar.xz
tbrpg.tar.xz: tbrpg.tar #implies $(RM) "$<"
	xz -e9 < "$<" > "$@"

.PHONY: tbrpg.shar
shar: tbrpg.shar
tbrpg.shar:
	shar $(AR_FILES) > "$@"

.PHONY: dist
dist: tbrpg-$(VERSION).tar.xz
tbrpg-$(VERSION).tar.xz:
	tar -c $(AR_FILES) | xz -e9 > "$@"


.PHONY: test check
check: test
test:
	@echo 'Not yet implemented'

