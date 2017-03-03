#ifndef JCLIB_PATH_H
#define JCLIB_PATH_H

#include <jclib/str.h>

#define PATH_SEP "/"

extern void path_join (str_type *dst, size_t count, char *str, ...);

#endif /* JCLIB_PATH_H */
