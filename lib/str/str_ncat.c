#include <jcaslib/str.h>
#include <string.h>

void
str_ncat (str_type *dst, const char *adds, size_t addlen)
{
    while (str_size (dst) < (dst->len + addlen - 1))
        str_realloc (dst);
    memcpy (dst->data + dst->len, adds, addlen);
    dst->len += addlen;
}
