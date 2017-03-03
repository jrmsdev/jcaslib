include ../mk/vars.mk

TESTS != ls *.c | sed 's/\.c/\.test/'
INCD = ../include
SCRIPTSD = ../scripts
TEST_SUITE ?= $(TESTS)

.PHONY: all
all: run

.PHONY: compile
compile: $(TEST_SUITE)

.PHONY: run
run: compile
	@TEST_SUITE="$(TEST_SUITE)" $(SCRIPTSD)/run-tests.sh

.SUFFIXES:
.SUFFIXES: .c .test
.c.test:
	$(CC) $(CFLAGS) -I$(INCD) -o $(.TARGET) $(.PREFIX).c

.PHONY: clean
clean:
	@rm -vf $(TESTS) *.test.fail

.PHONY: distclean
distclean: clean
