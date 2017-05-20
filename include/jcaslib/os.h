#ifndef JCASLIB_OS_H
#define JCASLIB_OS_H

#include <dirent.h>

#define OS_PATHSEP "/"

extern int os_isdir (const char *dpath);
extern int os_isfile (const char *path);
extern int os_islink (const char *path);

extern int os_lsdir (struct dirent ***dst, const char *dpath);

#endif /* JCASLIB_OS_H */
