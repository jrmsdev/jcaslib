#ifndef JCASLIB_OS_H
#define JCASLIB_OS_H

#include <dirent.h>

#define OS_SEP "/"

extern int os_lsdir (struct dirent ***dst, const char *dpath);

#endif /* JCASLIB_OS_H */
