include ../../mk1/vars.mk

SRCDIR := $(PWD)
BASEDIR != realpath $(SRCDIR)/../..
MODNAME != basename $(SRCDIR)
BUILDDIR := $(BASEDIR)/$(BUILDDIR_NAME)/lib/$(MODNAME)
INCDIR := $(BASEDIR)/include
MOD_DEPMK := $(BUILDDIR)/depend.mk

.PHONY: all
all: build

.PHONY: build
build: $(MOD_DEPMK)
	@(cd $(BUILDDIR) && $(MAKE) -f $(BASEDIR)/mk1/libmod.build.mk build)

$(MOD_DEPMK):
	@mkdir -vp $(BUILDDIR)
	$(CC) -I$(INCDIR) -E -MM $(SRCDIR)/*.c >$(MOD_DEPMK)

.PHONY: clean
clean:
	@rm -rfv $(BUILDDIR)
