include vars.mk

.PHONY: all
all: build


.PHONY: build
build:
	@$(MAKE) -C lib build
	@$(MAKE) -C bin build


.PHONY: clean
clean:
	@rm -vf .do-install
	@$(MAKE) -C lib clean
	@$(MAKE) -C bin clean
	@$(MAKE) -C examples clean


.PHONY: distclean
distclean:
	@$(MAKE) clean
	@$(MAKE) -C lib clean-depend
	@$(MAKE) -C bin clean-depend
	@$(MAKE) -C examples clean-depend
	@rm -rfv build


.PHONY: depend
depend:
	@$(MAKE) -C lib depend
	@$(MAKE) -C bin depend


.PHONY: examples
examples:
	@$(MAKE) -C examples all


.PHONY: install
install: build installdirs .do-install


.PHONY: installdirs
installdirs:
	@mkdir -vp $(DESTDIR)$(PREFIX)/include/jclib
	@mkdir -vp $(DESTDIR)$(PREFIX)/lib
	@mkdir -vp $(DESTDIR)$(PREFIX)/bin


.do-install: $(DESTDIR)$(PREFIX)/bin/jclib $(DESTDIR)$(PREFIX)/lib/libjc.a
	@$(INSTALL_F) include/jclib/*.h $(DESTDIR)$(PREFIX)/include/jclib
	@touch .do-install


$(DESTDIR)$(PREFIX)/bin/jclib: build/bin/jclib
	@$(INSTALL_EXE) build/bin/jclib $(DESTDIR)$(PREFIX)/bin/jclib


$(DESTDIR)$(PREFIX)/lib/libjc.a: build/lib/libjc.a
	@$(INSTALL_F) build/lib/libjc.a $(DESTDIR)$(PREFIX)/lib/libjc.a


.PHONY: uninstall
uninstall:
	@rm -vf $(DESTDIR)$(PREFIX)/bin/jclib $(DESTDIR)$(PREFIX)/lib/libjc.a
	@rm -rvf $(DESTDIR)$(PREFIX)/include/jclib
