include vars.mk

.PHONY: build
build:
	@make -C lib depend
	@make -C bin depend build

.PHONY: clean
clean:
	@make -C examples clean
	@make -C bin clean clean-depend
	@make -C lib clean-depend

.PHONY: install
install:
	@make clean && make build JCLIB_DEBUG=''
	@mkdir -vp $(PREFIX)/bin $(PREFIX)/lib $(PREFIX)/include/jclib
	@$(INSTALL_EXE) build/bin/jclib $(PREFIX)/bin/jclib
	@$(INSTALL_F) build/lib/libjc.a $(PREFIX)/lib/libjc.a
	@$(INSTALL_F) include/jclib/*.h $(PREFIX)/include/jclib/

.PHONY: deinstall
deinstall:
	@rm -vf $(PREFIX)/bin/jclib $(PREFIX)/lib/libjc.a
	@rm -rvf $(PREFIX)/include/jclib
