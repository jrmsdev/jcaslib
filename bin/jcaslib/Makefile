include ../../mk/vars.mk

INSTALL_BIN ?= true

include ../../mk/bin.mk

SCRIPTSD = ../../scripts

.build_info.h: $(SCRIPTSD)/build_info.sh
	@CC=$(CC) INCD=$(INCD) $(SCRIPTSD)/build_info.sh
	touch $(PWD)/.build_info.h

.PHONY: pre-build
pre-build: .build_info.h

.PHONY: clean-bin
clean-bin:
	@rm -vf $(PWD)/.build_info.h
