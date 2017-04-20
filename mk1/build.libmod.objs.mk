include ../../../mk1/vars.mk
include ../../../mk1/build.libmod.vars.mk

CFLAGS += -I$(INCDIR) -c -fPIC

# include auto-generated dependencies file
include depend.mk

.PHONY: build
build: $(MODOBJS)

$(MODOBJS):
	$(CC) $(CFLAGS) -o $@ $<
