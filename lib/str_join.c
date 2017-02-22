#include <jclib/str.h>
#include <stdarg.h>
#include <string.h>

void str_join (str_type *s, const char *sep, const char *str, ...)
{
    size_t seplen = strlen (sep);
    va_list ap;
    va_start (ap, str);
    for (const char *adds = str; adds != NULL; adds = va_arg (ap, const char*))
    {
        if (s->len > 0)
            str_ncat (s, sep, seplen);
        str_cat (s, adds);
    }
    va_end (ap);
}
