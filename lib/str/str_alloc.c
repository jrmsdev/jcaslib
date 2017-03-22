#include <jcaslib/str.h>
#include <jcaslib/lib.h>

str_type *
str_alloc ()
{
    str_type *s = (str_type *) xmalloc (sizeof (str_type));
    s->allocated = STR_ALLOC * sizeof (char);
    s->len = 0;
    s->data = (char *) xmalloc (str_size (s));
    return s;
}
