#include <jclib/str.h>
#include <string.h>

void
str_ncat (str_type *dst, const char *adds, size_t addlen)
{
    while (str_size (dst) < (dst->len + addlen - 1))
        str_realloc (dst);
    memcpy (dst->data + dst->len, adds, addlen);
    dst->len += addlen;
}

void
str_cat (str_type *dst, const char *adds)
{
    str_ncat (dst, adds, strlen (adds));
}
