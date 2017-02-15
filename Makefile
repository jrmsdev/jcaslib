include vars.mk

.PHONY: build
build:
	@$(MAKE) -C lib build
	@$(MAKE) -C bin build

.PHONY: clean
clean:
	@rm -vf .do-install
	@$(MAKE) -C lib clean
	@$(MAKE) -C bin clean

.PHONY: install
install: build .do-install

.do-install: $(PREFIX)/bin/jclib $(PREFIX)/lib/libjc.a
	@mkdir -vp $(PREFIX)/include/jclib
	@$(INSTALL_F) include/jclib/*.h $(PREFIX)/include/jclib
	@touch .do-install

$(PREFIX)/bin/jclib: build/bin/jclib
	@mkdir -vp $(PREFIX)/bin
	@$(INSTALL_EXE) build/bin/jclib $(PREFIX)/bin/jclib

$(PREFIX)/lib/libjc.a: build/lib/libjc.a
	@mkdir -vp $(PREFIX)/lib
	@$(INSTALL_F) build/lib/libjc.a $(PREFIX)/lib/libjc.a

.PHONY: deinstall
deinstall:
	@rm -vf $(PREFIX)/bin/jclib $(PREFIX)/lib/libjc.a
	@rm -rvf $(PREFIX)/include/jclib

.PHONY: examples
examples:
	@$(MAKE) -C examples all
