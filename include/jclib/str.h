#ifndef JCLIB_STR_H
#define JCLIB_STR_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define DEBUG 0
#define STR_ALLOC 50

extern char * str_init ();
extern char * str_init_len (size_t len);
extern char * str_join (size_t count, const char *sep, const char *str, ...);

#endif /* JCLIB_STR_H */
