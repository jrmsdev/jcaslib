include ../../../mk1/vars.mk
include ../../../mk1/inc.modvars.mk

CFLAGS += -I$(INCDIR) -c -fPIC

# include auto-generated dependencies file
include depend.mk

.PHONY: build
build: $(MODOBJS) $(MOD_LIBPATH)

$(MODOBJS):
	$(CC) $(CFLAGS) -o $@ $<

$(MOD_LIBPATH): $(MODOBJS)
	@rm -f $(MOD_LIBPATH)
	@ar -rc $(MOD_LIBPATH) $(MODOBJS)
	ranlib $(MOD_LIBPATH)
