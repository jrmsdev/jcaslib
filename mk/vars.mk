SH = /bin/sh
JCASLIB_DEBUG ?= 1
BUILD_COVERAGE ?= 0
COV_CFLAGS :=

.if $(BUILD_COVERAGE) == 1
COV_CFLAGS = -O0 -fprofile-arcs -fprofile-generate -ftest-coverage
LDFLAGS += -lgcov
.endif

CFLAGS += -pipe -march=native -std=c11
CFLAGS += -Wall -Wextra -pedantic -pedantic-errors
CFLAGS += $(COV_CFLAGS)

.if $(JCASLIB_DEBUG) == 0
.if $(BUILD_COVERAGE) != 1
CFLAGS += -O2
.endif
.else
CFLAGS += -O0 -ggdb
.endif

PREFIX ?= /opt/pkg

INSTALL_BACKUP ?=
INSTALL_EXE = install -v -m 0555 $(INSTALL_BACKUP)
INSTALL_F = install -v -m 0444 $(INSTALL_BACKUP)

GCOV_CC ?= gcc
GCOV_CMD ?= gcov5
GCOV_REPORT_SCRIPT ?= $(PREFIX)/bin/gcov-report
