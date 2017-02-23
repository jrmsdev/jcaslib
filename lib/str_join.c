#include <jclib/str.h>
#include <string.h>

void str_vjoin (str_type *s, const char *sep, const char *str, va_list ap)
{
    size_t seplen = strlen (sep);
    for (const char *adds = str; adds != NULL; adds = va_arg (ap, const char*))
    {
        if (s->len > 0)
            str_ncat (s, sep, seplen);
        str_cat (s, adds);
    }
}

void str_join (str_type *s, const char *sep, const char *str, ...)
{
    va_list ap;
    va_start (ap, str);
    str_vjoin (s, sep, str, ap);
    va_end (ap);
}
