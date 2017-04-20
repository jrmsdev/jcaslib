include ../../mk1/vars.mk

SRCDIR := $(PWD)
BASEDIR != realpath $(SRCDIR)/../..
CMDNAME != basename $(SRCDIR)
BUILDDIR := $(BASEDIR)/$(BUILDDIR_NAME)/bin/$(CMDNAME)

.PHONY: all
all: build

.PHONY: build
build:
	@mkdir -vp $(BUILDDIR)
	@(cd $(BUILDDIR) && $(MAKE) -f $(BASEDIR)/mk1/build.bincmd.mk build)

.PHONY: clean
clean:
	@rm -rfv $(BUILDDIR)
