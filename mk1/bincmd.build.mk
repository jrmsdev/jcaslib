include ../../../mk1/vars.mk

BUILDDIR := $(PWD)
BASEDIR != realpath $(BUILDDIR)/../../..
CMDNAME != basename $(BUILDDIR)
CMD_DEPMK := $(BUILDDIR)/depend.mk
INCDIR := $(BASEDIR)/include
SRCDIR := $(BASEDIR)/bin/$(CMDNAME)
CMDOBJS != ls $(SRCDIR)/*.c | xargs basename | sed 's/\.c/\.o/'
CMDBIN := $(BUILDDIR)/$(CMDNAME).bin
LIBFILE := $(BASEDIR)/$(BUILDDIR_NAME)/lib/libjcas.a

CFLAGS += -I$(INCDIR)
OBJS_CFLAGS := $(CFLAGS) -c -fPIC

# include auto-generated dependencies file
include depend.mk

.PHONY: build
build: buildlib $(CMDBIN)

buildlib:
	@(cd $(BASEDIR)/lib && $(MAKE) -f Makefile.1 build)

$(CMDBIN): $(LIBFILE) $(CMDOBJS)
	$(CC) $(CFLAGS) -o $@ $(CMDOBJS) $(LIBFILE)

$(CMDOBJS):
	$(CC) $(OBJS_CFLAGS) -o $@ $<
