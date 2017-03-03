include ../mk/vars.mk

TESTS != ls *_t.c | sed 's/_t\.c/_t\.run/'
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
.SUFFIXES: .c .run
.c.run:
	$(CC) $(CFLAGS) -I$(INCD) -o $(.TARGET) $(.PREFIX).c

.PHONY: clean
clean:
	@rm -vf $(TESTS) *_t.fail

.PHONY: distclean
distclean: clean clean-depend


.PHONY: depend
depend:
	$(CC) -I $(INCD) -E -MM *_t.c | sed 's/\.o:/\.run:/' >.depend


.PHONY: clean-depend
clean-depend:
	@rm -vf .depend
