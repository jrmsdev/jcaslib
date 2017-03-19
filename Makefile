.if exists(config.mk)
include config.mk
.endif
include mk/vars.mk


LIB_PATH = $(DESTDIR)$(PREFIX)/lib/libjc.a
SHARED_LIB_PATH = $(DESTDIR)$(PREFIX)/lib/libjc.so
DIST_VERSION != scripts/dist-version.sh


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
	@$(MAKE) -C examples depend


.PHONY: examples
examples:
	@$(MAKE) -C examples all


.PHONY: install
install: build installdirs .do-install


.PHONY: installdirs
installdirs:
	@mkdir -vp $(DESTDIR)$(PREFIX)/share/licenses/jclib
	@mkdir -vp $(DESTDIR)$(PREFIX)/include/jclib
	@mkdir -vp $(DESTDIR)$(PREFIX)/lib
	@mkdir -vp $(DESTDIR)$(PREFIX)/bin


.do-install: $(DESTDIR)$(PREFIX)/bin/jclib $(LIB_PATH) $(SHARED_LIB_PATH)
	@$(INSTALL_F) include/jclib/*.h $(DESTDIR)$(PREFIX)/include/jclib
	@$(INSTALL_F) LICENSE $(DESTDIR)$(PREFIX)/share/licenses/jclib
	@touch .do-install


$(DESTDIR)$(PREFIX)/bin/jclib: build/bin/jclib
	@$(INSTALL_EXE) build/bin/jclib $(DESTDIR)$(PREFIX)/bin/jclib


$(LIB_PATH): build/lib/libjc.a
	@$(INSTALL_F) build/lib/libjc.a $(LIB_PATH)


$(SHARED_LIB_PATH): build/lib/libjc.so
	@$(INSTALL_F) build/lib/libjc.so $(SHARED_LIB_PATH)


.PHONY: uninstall
uninstall:
	@rm -vf $(DESTDIR)$(PREFIX)/bin/jclib $(LIB_PATH) $(SHARED_LIB_PATH)
	@rm -rvf $(DESTDIR)$(PREFIX)/include/jclib
	@rm -rvf $(DESTDIR)$(PREFIX)/share/licenses/jclib


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
	@rm -rfv build dist config.mk


.PHONY: check
check:
	@$(MAKE) -C tests check
