include ../mk1/vars.mk

BASEDIR != realpath $(PWD)/..
BUILDDIR := $(BASEDIR)/$(BUILDDIR_NAME)/lib
LIBFILE := $(BUILDDIR)/libjcas.a

.PHONY: all
all: build

.PHONY: build
build: $(LIBFILE)

$(LIBFILE): buildmods
	rm -f $(LIBFILE)
	@(for mod in $(LIBMODS); do \
		ar -rc $(LIBFILE) $(BUILDDIR)/$${mod}/*.a; \
	done)
	ranlib $(LIBFILE)
	ar -tf $(LIBFILE)

.PHONY: buildmods
buildmods:
	@(for mod in $(LIBMODS); do \
		mkdir -vp $(BUILDDIR)/$$mod; \
		(cd $(BASEDIR)/lib/$$mod && $(MAKE) -f Makefile.1 build); \
	done)

.PHONY: clean
clean:
	@rm -vf $(LIB_PATH)
