include ../mk/vars.mk


INCD = ../include
SCRIPTSD = ../scripts
TESTSD = ../build/tests
LIB_TESTS != ls ../lib/*/*_t.c | sed 's/_t\.c/_t\.run/'
LIB_TEST_SUITE = $(LIB_TESTS:S/..\/lib\///)
TEST_SUITE ?= $(LIB_TEST_SUITE)

TEST_LIB_BINS =
.for t in $(LIB_TEST_SUITE)
TEST_LIB_BINS += $(TESTSD)/$(t)
.endfor

TEST_BINS =
.for t in $(TEST_SUITE)
TEST_BINS += $(TESTSD)/$(t)
.endfor


.PHONY: all
all: $(TEST_BINS)


.PHONY: check
check: all
	@TEST_SUITE="$(TEST_SUITE)" $(SCRIPTSD)/run-tests.sh


$(TEST_LIB_BINS): $(TESTSD)/test.o
	@mkdir -vp `dirname $(.TARGET)`
	$(CC) $(CFLAGS) -I$(INCD) -o $(.TARGET)\
		 $(.TARGET:S/..\/build\/tests/..\/lib/:S/.run/.c/) $(TESTSD)/test.o


$(TESTSD)/test.o: test.h test.c
	@mkdir -vp $(TESTSD)
	$(CC) $(CFLAGS) -I$(INCD) -fPIC -c -o $(TESTSD)/test.o test.c


.PHONY: clean
clean:
	@rm -vrf $(TESTSD)


.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend:
	CC=$(CC) INCD=$(INCD) $(SCRIPTSD)/tests-depend.sh >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend
