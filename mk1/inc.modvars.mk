MODDIR := $(PWD)
BASEDIR != realpath $(MODDIR)/../../..
MODNAME != basename $(MODDIR)
BUILDDIR := $(PWD)
MOD_DEPMK := $(BUILDDIR)/depend.mk
INCDIR := $(BASEDIR)/include
SRCDIR := $(BASEDIR)/lib/$(MODNAME)
MODOBJS != ls $(SRCDIR)/*.c | xargs basename | sed 's/\.c/\.o/'
