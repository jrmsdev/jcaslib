include ../../../mk1/vars.mk

BUILDDIR := $(PWD)
BASEDIR != realpath $(BUILDDIR)/../../..
INCDIR := $(BASEDIR)/include
MODNAME != basename $(PWD)
SRCDIR := $(BASEDIR)/lib/$(MODNAME)
MODOBJS != ls $(SRCDIR)/*.c | xargs basename | sed 's/\.c/\.o/'

CFLAGS += -I$(INCDIR) -c -fPIC

# include auto-generated dependencies file
include depend.mk

.PHONY: build
build: $(MODOBJS)

$(MODOBJS):
	$(CC) $(CFLAGS) -o $@ $<
