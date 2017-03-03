include mk/vars.mk

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
	@$(MAKE) -C tests clean


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


DIST_VERSION != grep -F ' JCL_VERSION ' include/jclib/version.h | \
			cut -d ' ' -f 3 | sed 's/"//g'


.PHONY: dist
dist:
	@$(MAKE) install DESTDIR=dist/work INSTALL_BACKUP=''
	@cd dist/work && tar -cJf ../jclib-v$(DIST_VERSION).txz ./*
	touch dist/jclib-v$(DIST_VERSION).txz


.PHONY: distclean
distclean:
	@$(MAKE) clean
	@$(MAKE) -C lib distclean
	@$(MAKE) -C bin distclean
	@$(MAKE) -C examples distclean
	@$(MAKE) -C tests distclean
	@rm -rfv build dist


.PHONY: configure
configure:
	@$(MAKE) -C lib configure
	@echo "you might want to run '$(MAKE) depend' now..."


.PHONY: check
check:
	@$(MAKE) -C tests all
