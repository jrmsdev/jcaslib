include ../../mk1/vars.mk

MODDIR := $(PWD)
BASEDIR != realpath $(MODDIR)/../..
MODNAME != basename $(MODDIR)
BUILDDIR := $(BASEDIR)/$(BUILDDIR_NAME)/lib/$(MODNAME)

.PHONY: all
all: build

.PHONY: build
build:
	@mkdir -vp $(BUILDDIR)
	@(cd $(BUILDDIR) && $(MAKE) -f $(BASEDIR)/mk1/build.libmod.mk build)

.PHONY: clean
clean:
	@rm -rfv $(BUILDDIR)/*.o
