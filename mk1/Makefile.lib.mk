include ../mk1/vars.mk

BASEDIR != realpath $(PWD)/..
BUILDDIR := $(BASEDIR)/$(BUILDDIR_NAME)/lib
LIBFILE := $(BUILDDIR)/libjcas.a

.PHONY: all
all: build

.PHONY: build
build: $(LIBFILE)

$(LIBFILE): buildmods
	@ar -rc $(LIBFILE) $(BUILDDIR)/*/*.a
	ranlib $(LIBFILE)

.PHONY: buildmods
buildmods:
	@(for mod in $(LIBMODS); do \
		mkdir -vp $(BUILDDIR)/$$mod; \
		(cd $(BASEDIR)/lib/$$mod && $(MAKE) -f Makefile.1 build); \
	done)

.PHONY: clean
clean:
	@rm -vf $(LIB_PATH)
