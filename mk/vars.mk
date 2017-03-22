SH = /bin/sh
JCASLIB_DEBUG ?=
CFLAGS += -Wall -Wextra -pedantic -pedantic-errors -std=c11 $(JCASLIB_DEBUG)

PREFIX ?= /opt/pkg

INSTALL_BACKUP ?=
INSTALL_EXE = install -v -m 0555 $(INSTALL_BACKUP)
INSTALL_F = install -v -m 0444 $(INSTALL_BACKUP)
