#ifndef JCASLIB_PATH_H
#define JCASLIB_PATH_H

#include <jcaslib/str.h>
#include <dirent.h>

#define PATH_SEP "/"

extern void path_join (str_type *dst, size_t count, char *str, ...);
extern int path_exists (const char *path);
extern int path_lsdir (struct dirent ***dst, const char *dpath);

#endif /* JCASLIB_PATH_H */
