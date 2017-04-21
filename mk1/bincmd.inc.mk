include ../../mk1/vars.mk

SRCDIR := $(PWD)
BASEDIR != realpath $(SRCDIR)/../..
CMDNAME != basename $(SRCDIR)
BUILDDIR := $(BASEDIR)/$(BUILDDIR_NAME)/bin/$(CMDNAME)

INCDIR := $(BASEDIR)/include
CMD_DEPMK := $(BUILDDIR)/depend.mk
CFLAGS += -I$(INCDIR)

.PHONY: all
all: build

.PHONY: build
build: $(CMD_DEPMK)
	@(cd $(BUILDDIR) && $(MAKE) -f $(BASEDIR)/mk1/bincmd.build.mk build)

$(CMD_DEPMK): *.c *.h
	@mkdir -vp $(BUILDDIR)
	$(CC) -I$(INCDIR) -E -MM $(SRCDIR)/*.c >$(CMD_DEPMK)

.PHONY: clean
clean:
	@rm -rfv $(BUILDDIR)
