JCLIB_DEBUG ?=
CFLAGS += -Wall -pedantic -std=c11 $(JCLIB_DEBUG)

PREFIX ?= /opt/pkg

INSTALL_EXE = install -v -m 0755 -b -B .old
INSTALL_F = install -v -m 0644 -b -B .old
