#ifndef JCLIB_STR_H
#define JCLIB_STR_H

#include <stdlib.h>
#include <stdarg.h>

#define STR_ALLOC 50

typedef struct {
    char *data;
    size_t len;
    size_t allocated;
} str_type;

extern str_type * str_alloc ();
extern void str_realloc (str_type *s);
extern void str_free (str_type *s);

extern void str_nset (str_type *dst, const char *adds, size_t addlen);
extern void str_set (str_type *dst, const char *adds);

extern void str_ncat (str_type *dst, const char *adds, size_t addlen);
extern void str_cat (str_type *dst, const char *adds);

extern void str_vjoin (str_type *dst, const char *sep, int count, const char *str, va_list ap);
extern void str_join (str_type *dst, const char *sep, int count, const char *str, ...);

/* macros */
#define str_get(s) s->data
#define str_len(s) s->len
#define str_size(s) s->allocated

#endif /* JCLIB_STR_H */
