include ../mk/vars.mk

.PATH: ../mk
.if exists(configure.mk)
include configure.mk
.endif

INCD = ../include
SCRIPTSD = ../scripts
TESTSD = ../build/tests
TESTLIB = ../build/lib/libjcas-test.a
TEST_NAMES != ls *_t.c | sed 's/_t\.c//'
TEST_SUITE ?= $(TEST_NAMES)
CHECK_COVERAGE ?= false

TEST_BINS =
.for t in $(TEST_SUITE)
TEST_BINS += $(TESTSD)/$(t)_t.run
.endfor

CFLAGS += -I$(INCD) $(CFLAGS_DEFINE) $(LD_FLAGS)


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
	$(CC) $(CFLAGS) -I$(INCD) -o $(.TARGET)\
		$(.TARGET:S/..\/build\/tests\///:S/.run/.c/) $(TESTLIB)


$(TESTLIB): build-testlib


.PHONY: build-testlib
build-testlib:
	@$(MAKE) -C ../lib/test build


.PHONY: clean
clean:
	@rm -vrf $(TESTSD) *.gcov *.gcno *.gcda gcovhtml .build-coverage
	@$(MAKE) -C ../lib/test clean


.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend:
	$(CC) -I$(INCD) -E -MM *_t.c |\
		sed 's#\(.*\)\.o:#$(TESTSD)/\1.run:#' >.depend
	@$(MAKE) -C ../lib/test depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend


.PHONY: build-coverage
build-coverage: .build-coverage


.build-coverage: $(TESTLIB)
	@$(MAKE) -C ../lib/test clean
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
