include ../mk1/vars.mk

BASEDIR != realpath $(PWD)/..
BUILDDIR := $(BASEDIR)/$(BUILDDIR_NAME)/lib
LIBFILE := $(BUILDDIR)/libjcas.a
LIBSRCS != ls */*.c */*.h

.PHONY: all
all: build

.PHONY: build
build: buildmods $(LIBFILE)

$(LIBFILE): $(LIBSRCS)
	@rm -f $(LIBFILE)
	@(for mod in $(BUILDMODS); do \
		ar -rc $(LIBFILE) $(BUILDDIR)/$${mod}/*.o; \
	done)
	ranlib $(LIBFILE)

.PHONY: buildmods
buildmods:
	@(for mod in $(BUILDMODS); do \
		mkdir -vp $(BUILDDIR)/$$mod; \
		(cd $(BASEDIR)/lib/$$mod && $(MAKE) -f Makefile.1 build); \
	done)

.PHONY: clean
clean:
	@rm -vrf $(BUILDDIR)
