#ifndef JCLIB_STR_H
#define JCLIB_STR_H

#include <stdlib.h>

#define STR_ALLOC 50

typedef struct {
    char *data;
    size_t len;
    size_t allocated;
} str_type;

extern str_type * str_alloc ();
extern void str_free (str_type *s);

#endif /* JCLIB_STR_H */
