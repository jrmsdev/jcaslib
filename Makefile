PREFIX ?= /opt/pkg

.PHONY: build
build:
	@make -C lib build
	@make -C bin build

.PHONY: clean
clean:
	@make -C bin clean
	@make -C lib clean

INSTALL_EXE = install -v -m 0755 -b -B .old
INSTALL_F = install -v -m 0644 -b -B .old

.PHONY: install
install: build
	@mkdir -vp $(PREFIX)/bin $(PREFIX)/lib $(PREFIX)/include/jclib
	@$(INSTALL_EXE) build/bin/jclib $(PREFIX)/bin/jclib
	@$(INSTALL_F) build/lib/libjc.a $(PREFIX)/lib/libjc.a
	@$(INSTALL_F) include/jclib/*.h $(PREFIX)/include/jclib/
