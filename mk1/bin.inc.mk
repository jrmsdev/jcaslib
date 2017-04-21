include ../mk1/vars.mk

BASEDIR != realpath $(PWD)/..
BUILDDIR := $(BASEDIR)/$(BUILDDIR_NAME)/bin

.PHONY: all
all: build

.PHONY: build
build:
	@(for bincmd in $(BUILDCMDS); do \
		mkdir -vp $(BUILDDIR)/$$bincmd; \
		(cd $(BASEDIR)/bin/$$bincmd && $(MAKE) -f Makefile.1 build); \
	done)

.PHONY: clean
clean:
	@rm -vrf $(BUILDDIR)
