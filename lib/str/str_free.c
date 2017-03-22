#include <jcaslib/str.h>

void str_free (str_type *s)
{
    s->len = 0;
    s->allocated = 0;
    free (s->data);
    s->data = NULL;
    free (s);
    s = NULL;
}
