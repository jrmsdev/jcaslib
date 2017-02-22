#include <jclib/str.h>
#include <string.h>

void str_nset (str_type *s, const char *adds, size_t addlen)
{
    while (s->allocated < (addlen + 1))
        str_realloc (s);
    memcpy (s->data, adds, addlen);
    s->len = addlen;
}

void str_set (str_type *s, const char *adds)
{
    str_nset (s, adds, strlen (adds));
}
