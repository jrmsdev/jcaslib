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

.PHONY: depend
depend:
	@$(MAKE) -C lib depend
	@$(MAKE) -C bin depend

.PHONY: examples
examples:
	@$(MAKE) -C examples all

.PHONY: install
install: build .do-install

.do-install: $(DESTDIR)$(PREFIX)/bin/jclib $(DESTDIR)$(PREFIX)/lib/libjc.a
	@mkdir -vp $(DESTDIR)$(PREFIX)/include/jclib
	@$(INSTALL_F) include/jclib/*.h $(DESTDIR)$(PREFIX)/include/jclib
	@touch .do-install

$(DESTDIR)$(PREFIX)/bin/jclib: build/bin/jclib
	@mkdir -vp $(DESTDIR)$(PREFIX)/bin
	@$(INSTALL_EXE) build/bin/jclib $(DESTDIR)$(PREFIX)/bin/jclib

$(DESTDIR)$(PREFIX)/lib/libjc.a: build/lib/libjc.a
	@mkdir -vp $(DESTDIR)$(PREFIX)/lib
	@$(INSTALL_F) build/lib/libjc.a $(DESTDIR)$(PREFIX)/lib/libjc.a

.PHONY: deinstall
deinstall:
	@rm -vf $(DESTDIR)$(PREFIX)/bin/jclib $(DESTDIR)$(PREFIX)/lib/libjc.a
	@rm -vf $(DESTDIR)$(PREFIX)/bin/jclib* $(DESTDIR)$(PREFIX)/lib/libjc.a*
	@rm -rvf $(DESTDIR)$(PREFIX)/include/jclib
