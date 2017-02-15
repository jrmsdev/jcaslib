include vars.mk

.PHONY: build
build:
	@$(MAKE) -C bin build

.PHONY: clean
clean:
	@$(MAKE) -C examples clean
	@$(MAKE) -C bin clean

.PHONY: install
install:
	@$(MAKE) clean && make build JCLIB_DEBUG=''
	@mkdir -vp $(PREFIX)/bin $(PREFIX)/lib $(PREFIX)/include/jclib
	@$(INSTALL_EXE) build/bin/jclib $(PREFIX)/bin/jclib
	@$(INSTALL_F) build/lib/libjc.a $(PREFIX)/lib/libjc.a
	@$(INSTALL_F) include/jclib/*.h $(PREFIX)/include/jclib/

.PHONY: deinstall
deinstall:
	@rm -vf $(PREFIX)/bin/jclib $(PREFIX)/lib/libjc.a
	@rm -rvf $(PREFIX)/include/jclib

.PHONY: examples
examples:
	@$(MAKE) -C examples all
