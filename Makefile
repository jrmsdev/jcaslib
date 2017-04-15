.PATH: ./mk
.if exists(configure.mk)
include configure.mk
.endif
include mk/vars.mk


LIB_PATH = $(DESTDIR)$(PREFIX)/lib/libjcas.a
SHARED_LIB_PATH = $(DESTDIR)$(PREFIX)/lib/libjcas.so
DIST_VERSION != ./scripts/dist-version.sh


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
	@mkdir -vp $(DESTDIR)$(PREFIX)/share/licenses/jcaslib
	@mkdir -vp $(DESTDIR)$(PREFIX)/include/jcaslib
	@mkdir -vp $(DESTDIR)$(PREFIX)/lib
	@mkdir -vp $(DESTDIR)$(PREFIX)/bin


.do-install: $(LIB_PATH) $(SHARED_LIB_PATH)
	@$(INSTALL_F) include/jcaslib/*.h $(DESTDIR)$(PREFIX)/include/jcaslib
	@rm -f $(DESTDIR)$(PREFIX)/include/jcaslib/configure.h
	@$(INSTALL_F) LICENSE $(DESTDIR)$(PREFIX)/share/licenses/jcaslib
	@$(MAKE) -C lib install
	@$(MAKE) -C bin install
	@touch .do-install


$(LIB_PATH): build/lib/libjcas.a
	@$(INSTALL_F) build/lib/libjcas.a $(LIB_PATH)


$(SHARED_LIB_PATH): build/lib/libjcas.so
	@$(INSTALL_F) build/lib/libjcas.so $(SHARED_LIB_PATH)


.PHONY: uninstall
uninstall:
	@rm -vf $(LIB_PATH) $(SHARED_LIB_PATH)
	@rm -rvf $(DESTDIR)$(PREFIX)/include/jcaslib
	@rm -rvf $(DESTDIR)$(PREFIX)/share/licenses/jcaslib
	@$(MAKE) -C lib uninstall
	@$(MAKE) -C bin uninstall


.PHONY: dist
dist:
	@$(MAKE) install DESTDIR=$(PWD)/dist/work INSTALL_BACKUP=''
	@(cd dist/work && tar -cJf ../jcaslib-v$(DIST_VERSION).txz \
		`find . -type f | sort`)
	touch dist/jcaslib-v$(DIST_VERSION).txz


.PHONY: distclean
distclean:
	@$(MAKE) clean
	@$(MAKE) -C lib distclean
	@$(MAKE) -C bin distclean
	@$(MAKE) -C examples distclean
	@$(MAKE) -C tests distclean
	@rm -rfv build dist mk/configure.mk include/jcaslib/configure.h


.PHONY: check
check:
	@$(MAKE) -C tests check


.PHONY: check-valgrind
check-valgrind:
	@$(MAKE) -C tests check-valgrind


.PHONY: expand
expand:
	@./scripts/expand-tabs.sh


.PHONY: check-coverage
check-coverage:
	@$(MAKE) -C tests check-coverage
