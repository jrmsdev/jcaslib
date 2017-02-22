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
extern void str_realloc (str_type *s);
extern void str_free (str_type *s);

extern void str_nset (str_type *s, const char *adds, size_t addlen);
extern void str_set (str_type *s, const char *adds);

extern void str_ncat (str_type *s, const char *adds, size_t addlen);
extern void str_cat (str_type *s, const char *adds);

extern void str_join (str_type *s, const char *sep, const char *str, ...);

/* str_get macro */
#define str_get(s) s->data

#endif /* JCLIB_STR_H */
