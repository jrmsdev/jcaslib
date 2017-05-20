#ifndef JCASLIB_PATH_H
#define JCASLIB_PATH_H

#include <jcaslib/str.h>

extern int path_exists (const char *path);

extern char * path_filename_ext (const char *path);

extern int path_isdir (const char *path);
extern int path_isfile (const char *path);
extern int path_islink (const char *path);

extern void path_join (str_type *dst, size_t count, char *str, ...);

#endif /* JCASLIB_PATH_H */
