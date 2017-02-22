#include <jclib/str.h>
#include <string.h>

void str_ncat (str_type *s, const char *adds, size_t addlen)
{
    while (s->allocated < (s->len + addlen - 1))
        str_realloc (s);
    memcpy (s->data + s->len, adds, addlen);
    s->len += addlen;
}

void str_cat (str_type *s, const char *adds)
{
    str_ncat (s, adds, strlen (adds));
}
