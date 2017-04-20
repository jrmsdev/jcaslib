SH = /bin/sh
MODDIR := $(PWD)
SRCDIR != realpath $(MODDIR)/../..
MODNAME != basename $(MODDIR)
BUILDDIR := $(SRCDIR)/build1/lib/$(MODNAME)

# -- main targets

.PHONY: all
all: build

.PHONY: build
build:
	@mkdir -vp $(BUILDDIR)
	$(MAKE) -C $(BUILDDIR) -f $(SRCDIR)/mk1/build.libmod.mk build

.PHONY: clean
clean:
	@rm -rfv $(BUILDDIR)
