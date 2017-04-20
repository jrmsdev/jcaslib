include ../../../mk1/vars.mk
include ../../../mk1/inc.modvars.mk

CFLAGS += -I$(INCDIR) -c -fPIC

# include auto-generated dependencies file
include depend.mk

.PHONY: build
build: $(MODOBJS)
	@echo "build.modobjs: $(PWD)"
	@echo "build.modobjs: $(MODOBJS)"
