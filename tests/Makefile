include ../mk/vars.mk


INCD = ../include
SCRIPTSD = ../scripts
TESTSD = ../build/tests
TESTLIB = ../build/lib/libjcas-test.a
TEST_FILES != ls *_t.c | sed 's/_t\.c/_t\.run/'
TEST_SUITE ?= $(TEST_FILES)

TEST_BINS =
.for t in $(TEST_SUITE)
TEST_BINS += $(TESTSD)/$(t)
.endfor


.PHONY: all
all: $(TEST_BINS)


.PHONY: check
check: all
	@TEST_SUITE="$(TEST_SUITE)" $(SCRIPTSD)/run-tests.sh


.PHONY: check-valgrind
check-valgrind: all
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
	@rm -vrf $(TESTSD)


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
