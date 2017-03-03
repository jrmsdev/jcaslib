include ../mk/vars.mk

TESTS != ls *.c | sed 's/\.c/\.test/'
INCD = ../include
SCRIPTSD = ../scripts

.PHONY: all
all: run

.PHONY: compile
compile: $(TESTS)

.PHONY: run
run: compile
	@$(SCRIPTSD)/run-tests.sh

.SUFFIXES:
.SUFFIXES: .c .test
.c.test:
	$(CC) $(CFLAGS) -I$(INCD) -o $(.TARGET) $(.PREFIX).c

.PHONY: clean
clean:
	@rm -vf $(TESTS)

.PHONY: distclean
distclean: clean
