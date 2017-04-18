SH = /bin/sh
JCASLIB_DEBUG ?=
BUILD_COVERAGE ?= 0

.if $(BUILD_COVERAGE) == 1
JCASLIB_DEBUG += -coverage -fprofile-arcs -ftest-coverage -O0
.endif

CFLAGS += -Wall -Wextra -pedantic -pedantic-errors -std=c11 $(JCASLIB_DEBUG)

PREFIX ?= /opt/pkg

INSTALL_BACKUP ?=
INSTALL_EXE = install -v -m 0555 $(INSTALL_BACKUP)
INSTALL_F = install -v -m 0444 $(INSTALL_BACKUP)

GCOV_CC ?= gcc
GCOV_CMD ?= gcov5
GCOV_REPORT_SCRIPT ?= $(PREFIX)/bin/gcov-report
