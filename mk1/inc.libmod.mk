include ../../mk1/vars.mk

SRCDIR := $(PWD)
BASEDIR != realpath $(SRCDIR)/../..
MODNAME != basename $(SRCDIR)
BUILDDIR := $(BASEDIR)/$(BUILDDIR_NAME)/lib/$(MODNAME)

.PHONY: all
all: build

.PHONY: build
build:
	@mkdir -vp $(BUILDDIR)
	@(cd $(BUILDDIR) && $(MAKE) -f $(BASEDIR)/mk1/build.libmod.mk build)

.PHONY: clean
clean:
	@rm -rfv $(BUILDDIR)
