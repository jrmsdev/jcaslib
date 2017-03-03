#include <jclib/str.h>

void str_free (str_type *s)
{
    s->len = 0;
    s->allocated = 0;
    free (s->data);
    free (s);
}
