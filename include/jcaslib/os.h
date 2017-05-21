#ifndef JCASLIB_OS_H
#define JCASLIB_OS_H

#include <jcaslib/str.h>

#define OS_SEP "/"
#define OS_MAXDEPTH 128

extern void os_lsdir (str_array_type *dst, const char *dpath, int maxdepth);

#endif /* JCASLIB_OS_H */
