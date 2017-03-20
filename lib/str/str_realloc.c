#include <jclib/str.h>
#include <jclib/lib.h>
#include <strings.h>

void
str_realloc (str_type *s)
{
    char *d = (char *) xrealloc (s->data,
            str_size (s) + (STR_ALLOC * sizeof (char)));
    s->allocated += (STR_ALLOC * sizeof (char));
    s->data = d;
    bzero (s->data + s->len, str_size (s) - s->len);
}
