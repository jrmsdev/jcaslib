BUILDD ?= ../build/lib
INCD ?= ../include/jclib
CFLAGS += -Wall -pedantic -std=c11 -fPIC -c

.PHONY: build
build: .pre-build .build_info.h $(BUILDD)/libjc.a

.PHONY: .pre-build
.pre-build:
	@mkdir -vp $(BUILDD)

OBJ_CC = $(CC) $(CFLAGS) -I ../include
OBJS = $(BUILDD)/build_info.o $(BUILDD)/version.o $(BUILDD)/log.o

$(BUILDD)/log.o: $(INCD)/log.h log.c
	$(OBJ_CC) -o $(BUILDD)/log.o log.c

$(BUILDD)/version.o: $(INCD)/version.h version.c
	$(OBJ_CC) -o $(BUILDD)/version.o version.c

$(BUILDD)/build_info.o: $(INCD)/build_info.h build_info.c
	$(OBJ_CC) -o $(BUILDD)/build_info.o build_info.c

$(BUILDD)/libjc.a: $(OBJS)
	ar -rc $(BUILDD)/libjc.a $(OBJS)

.build_info.h:
	touch .build_info.h
	@echo "#define JCL_BUILD_TIME \"`date -R`\"" >.build_info.h
	@echo "#define JCL_BUILD_BY \"`id -un`@`uname -n`\"" >>.build_info.h
	@echo "#define JCL_BUILD_EPOCH \"`date '+%s'`\"" >>.build_info.h
	@echo "#define JCL_BUILD_OS \"`uname -snrm`\"" >>.build_info.h
	@echo "#define JCL_CC_VERSION \"`$(CC) --version | head -n 1`\"" >>.build_info.h

.PHONY: clean
clean:
	@rm -vrf .build_info.h $(BUILDD)
