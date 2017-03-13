.ifdef USE_GDBM
CFG_CFLAGS_DEFINE += -DUSE_GDBM
CFG_LD_CFLAGS += -lgdbm_compat
.endif


.PHONY: configure
configure:
	@echo 'LD_CFLAGS += $(CFG_LD_CFLAGS)' >$(PWD)/.opts.mk
	@echo 'CFLAGS_DEFINE += $(CFG_CFLAGS_DEFINE)' >>$(PWD)/.opts.mk
	touch $(PWD)/.opts.mk
