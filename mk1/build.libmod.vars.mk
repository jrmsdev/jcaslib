BUILDDIR := $(PWD)
BASEDIR != realpath $(BUILDDIR)/../../..
MODNAME != basename $(BUILDDIR)
MOD_DEPMK := $(BUILDDIR)/depend.mk
INCDIR := $(BASEDIR)/include
SRCDIR := $(BASEDIR)/lib/$(MODNAME)
MODOBJS != ls $(SRCDIR)/*.c | xargs basename | sed 's/\.c/\.o/'
