BUILDDIR := $(PWD)
BASEDIR != realpath $(BUILDDIR)/../../..
CMDNAME != basename $(BUILDDIR)
CMD_DEPMK := $(BUILDDIR)/depend.mk
INCDIR := $(BASEDIR)/include
SRCDIR := $(BASEDIR)/bin/$(CMDNAME)
CMDOBJS != ls $(SRCDIR)/*.c | xargs basename | sed 's/\.c/\.o/'
CMDBIN := $(BUILDDIR)/$(CMDNAME).bin
