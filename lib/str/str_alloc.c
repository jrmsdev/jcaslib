#include <jcaslib/str.h>
#include <jcaslib/lib.h>

str_type *
str_alloc (const char *str)
{
    str_type *s = (str_type *) xmalloc (sizeof (str_type));
    s->allocated = STR_ALLOC * sizeof (char);
    s->len = 0;
    s->data = (char *) xmalloc (s->allocated);
    if (str != NULL)
        str_set (s, str);
    return s;
}
