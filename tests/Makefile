include ../mk/vars.mk


INCD = ../include
SCRIPTSD = ../scripts
TESTSD = ../build/tests
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


$(TEST_BINS): $(TESTSD)/test.o
	@mkdir -p $(TESTSD)
	$(CC) $(CFLAGS) -I$(INCD) -o $(.TARGET)\
		 $(.TARGET:S/..\/build\/tests\///:S/.run/.c/) $(TESTSD)/test.o


$(TESTSD)/test.o: test.h test.c
	@mkdir -p $(TESTSD)
	$(CC) $(CFLAGS) -I$(INCD) -fPIC -c -o $(TESTSD)/test.o test.c


.PHONY: clean
clean:
	@rm -vrf $(TESTSD)


.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend:
	$(CC) -I$(INCD) -E -MM test.c |\
		sed 's#^#$(TESTSD)/#' >.depend
	$(CC) -I$(INCD) -E -MM *_t.c |\
		sed 's#\(.*\)\.o:#$(TESTSD)/\1.run:#' >>.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend
