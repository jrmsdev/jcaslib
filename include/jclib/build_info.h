#ifndef JCLIB_BUILD_INFO_H
#define JCLIB_BUILD_INFO_H

#ifndef JCL_BUILD_TIME
#define JCL_BUILD_TIME "NOVAL"
#endif
#ifndef JCL_BUILD_BY
#define JCL_BUILD_BY "NOVAL"
#endif
#ifndef JCL_BUILD_EPOCH
#define JCL_BUILD_EPOCH "NOVAL"
#endif
#ifndef JCL_BUILD_OS
#define JCL_BUILD_OS "NOVAL"
#endif
#ifndef JCL_CC_VERSION
#define JCL_CC_VERSION "NOVAL"
#endif
#ifndef JCL_MODULES
#define JCL_MODULES "NOVAL"
#endif

extern void print_build_info();

#endif /* JCLIB_BUILD_INFO_H */
