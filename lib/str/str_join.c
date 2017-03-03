#include <jclib/str.h>
#include <string.h>

void
str_vjoin (str_type *dst, const char *sep, int count, const char *str, va_list ap)
{
    int idx = 0;
    size_t seplen = strlen (sep);
    for (const char *adds = str; idx < count; adds = va_arg (ap, const char*))
    {
        if (dst->len > 0)
            str_ncat (dst, sep, seplen);
        str_cat (dst, adds);
        idx++;
    }
}

void
str_join (str_type *dst, const char *sep, int count, const char *str, ...)
{
    va_list ap;
    va_start (ap, str);
    str_vjoin (dst, sep, count, str, ap);
    va_end (ap);
}
