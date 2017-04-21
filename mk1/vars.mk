SH := /bin/sh
CFLAGS += -Wall -Wextra -pedantic -pedantic-errors -std=c11 $(JCASLIB_CFLAGS)

BUILDDIR_NAME := build1
BUILDMODS ?= cfg db lib log path str test
BUILDCMDS ?= jcaslib
