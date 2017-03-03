include ../mk/vars.mk

TESTS != ls *_t.c | sed 's/_t\.c/_t\.run/'
INCD = ../include
SCRIPTSD = ../scripts
TEST_SUITE ?= $(TESTS)

.PHONY: all
all: $(TEST_SUITE)

.PHONY: check
check: all
	@TEST_SUITE="$(TEST_SUITE)" $(SCRIPTSD)/run-tests.sh

.SUFFIXES:
.SUFFIXES: .c .run
.c.run: test.o
	$(CC) $(CFLAGS) -I$(INCD) -o $(.TARGET) $(.PREFIX).c test.o

test.o: test.h test.c
	$(CC) $(CFLAGS) -I$(INCD) -fPIC -c -o test.o test.c

.PHONY: clean
clean:
	@rm -vf $(TESTS) test.o *_t.fail

.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend:
	$(CC) -I$(INCD) -E -MM *_t.c | sed 's/\.o:/\.run:/' >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend
