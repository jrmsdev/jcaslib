include ../../../mk1/vars.mk
include ../../../mk1/inc.modvars.mk

.PHONY: build
build:
	@$(CC) -I$(INCDIR) -E -MM $(SRCDIR)/*.c >$(MOD_DEPMK)
	@$(MAKE) -f $(BASEDIR)/mk1/build.modobjs.mk build
