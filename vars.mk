CFLAGS += -Wall -pedantic -std=c11 -ggdb

PREFIX ?= /opt/pkg

INSTALL_EXE = install -v -m 0755 -b -B .old
INSTALL_F = install -v -m 0644 -b -B .old
