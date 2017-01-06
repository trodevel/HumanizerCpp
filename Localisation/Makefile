# Makefile for libLocalisation
# Copyright (C) 2015 Sergey Kolevatov

###################################################################

VER := 0

MODE ?= debug

###################################################################

EXT_LIBS=

###################################################################

PROJECT := Localisation

LIBNAME=libLocalisation

###################################################################

ifeq "$(MODE)" "debug"
    OBJDIR=./DBG
    BINDIR=./DBG

    CFLAGS := -Wall -std=c++0x -ggdb -g3 -Wl,--no-as-needed
    LFLAGS := -Wall -lstdc++ -lrt -ldl -lm -g
    LFLAGS_TEST := -Wall -lstdc++ -lrt -ldl -g -L. -lm $(LFLAGS_STAT)
else
    OBJDIR=./OPT
    BINDIR=./OPT

    CFLAGS := -Wall -std=c++0x -Wl,--no-as-needed
    LFLAGS := -Wall -lstdc++ -lrt -ldl -lm
    LFLAGS_TEST := -Wall -lstdc++ -lrt -ldl -L. -lm $(LFLAGS_STAT)
endif

###################################################################

CC=gcc

LDSHARED=gcc
CPP=gcc -E
INCL = -I$(BOOST_INC) -I.


STATICLIB=$(LIBNAME).a
SHAREDLIB=
SHAREDLIBV=
SHAREDLIBM=
LIBS=$(STATICLIB) $(SHAREDLIBV)

AR=ar
RANLIB=ranlib
LDCONFIG=ldconfig
LDSHAREDLIBC=-lc
TAR=tar
SHELL=/bin/sh
EXE=

SRCC =

OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCC)) $(patsubst %.c,$(OBJDIR)/%.o,$(SRCC))

LIB_NAMES = NumberToWords
LIBS = $(patsubst %,$(BINDIR)/lib%.a,$(LIB_NAMES))

all: static

static: $(BINDIR) $(BINDIR)/$(STATICLIB)
	@echo "$@ uptodate - ${MODE}"

check: test

test: all teststatic

teststatic: static
	@echo static test is not ready yet, dc10

$(BINDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

$(BINDIR)/$(STATICLIB): $(LIBS)
	$(AR) -qc $@ $(BINDIR)/*.o
	#-@ ($(RANLIB) $@ || true) >/dev/null 2>&1

$(OBJDIR)/%.o: %.cpp
	@echo compiling $<
	$(CC) $(CFLAGS) -DPIC -c -o $@ $< $(INCL)

$(OBJDIR)/%.o: %.c
	@echo compiling $<
	$(CC) $(CFLAGS) -DPIC -c -o $@ $< $(INCL)

$(BINDIR)/libNumberToWords.a: NumberToWords
	make -C $<
	ln -sf ../$</$@ $(BINDIR); \
	cd $(BINDIR); \
	ar -x ../$(BINDIR)/libNumberToWords.a

clean:
	- rm $(OBJDIR)/*.o $(BINDIR)/$(STATICLIB)
