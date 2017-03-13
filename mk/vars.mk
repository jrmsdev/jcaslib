SH = /bin/sh
JCLIB_DEBUG ?=
CFLAGS += -Wall -Wextra -pedantic -pedantic-errors -std=c11 $(JCLIB_DEBUG)

PREFIX ?= /opt/pkg

INSTALL_BACKUP ?=
INSTALL_EXE = install -v -m 0555 $(INSTALL_BACKUP)
INSTALL_F = install -v -m 0444 $(INSTALL_BACKUP)
