#include <jclib/str.h>
#include <jclib/lib.h>
#include <string.h>

str_type * str_alloc ()
{
    str_type *s = (str_type *) xmalloc (sizeof (str_type *));
    s->len = 0;
    s->allocated = STR_ALLOC;
    s->data = (char *) xmalloc (STR_ALLOC);
    memset (s->data, 0, STR_ALLOC);
    return s;
}
