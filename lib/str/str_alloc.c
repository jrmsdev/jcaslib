#include <jclib/str.h>
#include <jclib/lib.h>
#include <string.h>


str_type *
str_alloc ()
{
    str_type *s = (str_type *) xmalloc (sizeof (str_type));
    s->allocated = STR_ALLOC * sizeof (char);
    s->len = 0;
    s->data = (char *) xmalloc (s->allocated);
    return s;
}


void
str_realloc (str_type *s)
{
    char *d = (char *) xrealloc (s->data, s->allocated + STR_ALLOC);
    s->allocated += STR_ALLOC;
    s->data = d;
    bzero (s->data + s->len, s->allocated - s->len);
}
