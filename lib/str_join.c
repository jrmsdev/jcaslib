#include <jclib/str.h>
#include <string.h>

void
str_vjoin (str_type *s, const char *sep, int count, const char *str, va_list ap)
{
    int idx = 0;
    size_t seplen = strlen (sep);
    for (const char *adds = str; idx < count; adds = va_arg (ap, const char*))
    {
        if (s->len > 0)
            str_ncat (s, sep, seplen);
        str_cat (s, adds);
        idx++;
    }
}

void
str_join (str_type *s, const char *sep, int count, const char *str, ...)
{
    va_list ap;
    va_start (ap, str);
    str_vjoin (s, sep, count, str, ap);
    va_end (ap);
}
