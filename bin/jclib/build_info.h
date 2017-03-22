#ifndef JCASLIB_BUILD_INFO_H
#define JCASLIB_BUILD_INFO_H

#include ".build_info.h"

#ifndef JCASLIB_BUILD_TIME
#define JCASLIB_BUILD_TIME "NOVAL"
#endif
#ifndef JCASLIB_BUILD_BY
#define JCASLIB_BUILD_BY "NOVAL"
#endif
#ifndef JCASLIB_BUILD_OS
#define JCASLIB_BUILD_OS "NOVAL"
#endif
#ifndef JCASLIB_CC_VERSION
#define JCASLIB_CC_VERSION "NOVAL"
#endif
#ifndef JCASLIB_MODULES
#define JCASLIB_MODULES "NOVAL"
#endif

#ifdef LOAD_CONFIGURE_H
#include <jclib/configure.h>
#endif

#ifndef CONFIGURE_OPTS
#define CONFIGURE_OPTS "NOVAL"
#endif

extern void print_build_info();

#endif /* JCASLIB_BUILD_INFO_H */
