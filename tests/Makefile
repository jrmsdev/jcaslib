include ../mk/vars.mk

.PATH: ../mk
.if exists(configure.mk)
include configure.mk
.endif

INCD != realpath ../include
SCRIPTSD != realpath ../scripts
TESTSD != echo $$(realpath $(PWD)/..)/build/tests
TESTLIB != echo $$(realpath $(PWD)/..)/build/lib/libjcas.a
TEST_NAMES != ls *_t.c | sed 's/_t\.c//'
TEST_SUITE ?= $(TEST_NAMES)
CHECK_COVERAGE ?= false

TEST_BINS =
.for t in $(TEST_SUITE)
TEST_BINS += $(TESTSD)/$(t)_t.run
.endfor

CFLAGS += $(CFLAGS_DEFINE) $(LD_FLAGS)


.PHONY: all
all: build


.PHONY: build
build: $(TEST_BINS)


.PHONY: check
check: build
	@TEST_SUITE="$(TEST_SUITE)" CHECK_COVERAGE=$(CHECK_COVERAGE) \
		$(SCRIPTSD)/run-tests.sh


.PHONY: check-valgrind
check-valgrind: build
	@TEST_SUITE="$(TEST_SUITE)" $(SCRIPTSD)/run-tests.sh --valgrind


$(TEST_BINS): $(TESTLIB) ../lib/test/*.c ../include/jcaslib/test.h
	@mkdir -p $(TESTSD)
	$(CC) $(CFLAGS) -I$(INCD) $(LDFLAGS) -o $(.TARGET)\
		$(.TARGET:S/$(TESTSD)\///:S/.run/.c/) $(TESTLIB)


$(TESTLIB): build-testlib


.PHONY: build-testlib
build-testlib:
	@$(MAKE) -C ../lib build CC=$(CC) BUILD_COVERAGE=$(BUILD_COVERAGE)


.PHONY: clean
clean:
	@rm -vrf $(TESTSD) $(PWD)/*.gcov $(PWD)/*.gcno
	@rm -vrf $(PWD)/*.gcda $(PWD)/gcovhtml $(PWD)/.build-coverage
	@$(MAKE) -C ../lib clean


.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend:
	$(CC) -I$(INCD) $(CFLAGS_DEFINE) -E -MM *_t.c |\
		sed 's#\(.*\)\.o:#$(TESTSD)/\1.run:#' >$(PWD)/.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf $(PWD)/.depend


.PHONY: build-coverage
build-coverage:
	@$(MAKE) build-testlib CC=$(GCOV_CC) BUILD_COVERAGE=1
	@$(MAKE) build CC=$(GCOV_CC) BUILD_COVERAGE=1
	@touch .build-coverage


.PHONY: check-coverage
check-coverage: build-coverage
	@$(MAKE) check CHECK_COVERAGE=true
	@GCOV_CC=$(GCOV_CC) GCOV_CMD=$(GCOV_CMD) $(SCRIPTSD)/run-gcov.sh


.PHONY: gcovhtml
gcovhtml:
	@rm -rf gcovhtml
	@mkdir -p gcovhtml
	@test -x $(GCOV_REPORT_SCRIPT)
	@$(GCOV_REPORT_SCRIPT)


.PHONY: gcovmiss
gcovmiss:
	@$(SCRIPTSD)/gcov-miss.py


.PHONY: gcovincludes
gcovincludes:
	@$(SCRIPTSD)/gcov-includes.py >includes_t.c
