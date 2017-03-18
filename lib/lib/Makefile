include ../../mk/vars.mk
include ../../mk/libmod.mk

SCRIPTSD = ../../scripts


.build_info.h: $(SCRIPTSD)/build_info.sh
	@CC=$(CC) INCD=$(INCD) $(SCRIPTSD)/build_info.sh
	touch $(PWD)/.build_info.h


.PHONY: pre-build
pre-build: .build_info.h


.PHONY: clean-mod
clean-mod:
	@rm -vf $(PWD)/.build_info.h
