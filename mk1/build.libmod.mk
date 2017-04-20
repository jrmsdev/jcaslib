include ../../../mk1/vars.mk
include ../../../mk1/inc.modvars.mk

.PHONY: build
build:
	@echo "build.libmod: $(PWD)"
	@echo "build.libmod: $(BASEDIR)"
	@echo "build.libmod: $(MOD_DEPMK)"
	$(CC) -I$(INCDIR) -E -MM $(SRCDIR)/*.c >$(MOD_DEPMK)
	$(MAKE) -f $(BASEDIR)/mk1/build.modobjs.mk build
