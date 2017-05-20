#ifndef JCASLIB_PATH_H
#define JCASLIB_PATH_H

#include <jcaslib/str.h>

extern void path_join (str_type *dst, size_t count, char *str, ...);
extern int path_exists (const char *path);

#endif /* JCASLIB_PATH_H */
