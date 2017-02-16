#ifndef JCLIB_STR_H
#define JCLIB_STR_H

#include <stdarg.h>

#define STR_ALLOC 50

extern char * str_join (size_t count, const char *sep, char *str, ...);

#endif /* JCLIB_STR_H */
