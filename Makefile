# Makefile for libHumanizerCpp
# Copyright (C) 2015 Sergey Kolevatov

###################################################################

VER := 0

MODE ?= debug

###################################################################

EXT_LIBS=

###################################################################

PROJECT := HumanizerCpp

LIBNAME=libHumanizerCpp

###################################################################

ifeq "$(MODE)" "debug"
    OBJDIR=./DBG
    BINDIR=./DBG

    CFLAGS := -Wall -std=c++0x -ggdb -g3 -Wl,--no-as-needed
    LFLAGS := -Wall -lstdc++ -lrt -ldl -lm -g
    LFLAGS_TEST := -Wall -lstdc++ -lrt -ldl -g -L. -lm $(LFLAGS_STAT)

    TARGET=example
else
    OBJDIR=./OPT
    BINDIR=./OPT

    CFLAGS := -Wall -std=c++0x -Wl,--no-as-needed
    LFLAGS := -Wall -lstdc++ -lrt -ldl -lm
    LFLAGS_TEST := -Wall -lstdc++ -lrt -ldl -L. -lm $(LFLAGS_STAT)

    TARGET=example
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

LIB_NAMES = Configuration Localisation
LIBS = $(patsubst %,$(BINDIR)/lib%.a,$(LIB_NAMES))

all: static

static: $(TARGET)

check: test

test: all teststatic

teststatic: static
	@echo static test is not ready yet, dc10

$(BINDIR)/$(STATICLIB): $(LIBS)
	$(AR) -qc $@ $(BINDIR)/*.o
	-@ ($(RANLIB) $@ || true) >/dev/null 2>&1

$(OBJDIR)/%.o: %.cpp
	@echo compiling $<
	$(CC) $(CFLAGS) -DPIC -c -o $@ $< $(INCL)

$(OBJDIR)/%.o: %.c
	@echo compiling $<
	$(CC) $(CFLAGS) -DPIC -c -o $@ $< $(INCL)

$(TARGET): $(BINDIR) $(BINDIR)/$(TARGET) 
	ln -sf $(BINDIR)/$(TARGET) $(TARGET)
	@echo "$@ uptodate - ${MODE}"

$(BINDIR)/$(TARGET): $(LIBS) $(OBJDIR)/$(TARGET).o $(OBJS) $(BINDIR)/$(STATICLIB)
	$(CC) $(CFLAGS) -o $@ $(OBJDIR)/$(TARGET).o $(BINDIR)/$(LIBNAME).a $(LIBS) $(EXT_LIBS) $(LFLAGS_TEST)

$(BINDIR)/libConfiguration.a: Configuration
	make -C $<
	ln -sf ../$</$@ $(BINDIR); \
	cd $(BINDIR); \
	ar -x ../$@

$(BINDIR)/libLocalisation.a: Localisation
	make -C $<
	ln -sf ../$</$@ $(BINDIR); \
	cd $(BINDIR); \
	ar -x ../$@

$(BINDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

clean:
	- rm $(OBJDIR)/*.o $(TARGET) $(BINDIR)/$(TARGET) $(BINDIR)/$(STATICLIB)
	- rm $(LIBS)

cleanall:
	for s in $(LIB_NAMES); \
	do \
	    cd $$s; make clean; cd ..;\
	done;