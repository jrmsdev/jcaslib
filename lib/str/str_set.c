#include <jclib/str.h>
#include <string.h>

void
str_nset (str_type *dst, const char *adds, size_t addlen)
{
    while (str_size (dst) < (addlen + 1))
        str_realloc (dst);
    memcpy (dst->data, adds, addlen);
    dst->len = addlen;
}

void str_set (str_type *dst, const char *adds)
{
    str_nset (dst, adds, strlen (adds));
}
