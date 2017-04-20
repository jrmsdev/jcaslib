include ../../../mk1/vars.mk
include ../../../mk1/build.bincmd.vars.mk

CFLAGS += -I$(INCDIR) -c -fPIC

# include auto-generated dependencies file
include depend.mk

.PHONY: build
build: $(CMDOBJS)

$(CMDOBJS):
	$(CC) $(CFLAGS) -o $@ $<
