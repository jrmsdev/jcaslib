include ../../mk/vars.mk
include ../../mk/libmod.mk


.ifdef USE_GDBM
CFG_CFLAGS_DEFINE += -DUSE_GDBM
.endif


.PHONY: configure
configure:
	@rm -f .opts.mk ; touch .opts.mk
	@echo 'CFLAGS_DEFINE += $(CFG_CFLAGS_DEFINE)' >>.opts.mk
	touch .opts.mk
