#include <jclib/str.h>
#include <stdio.h>

int main (void)
{
    str_type *s = str_alloc ();
    printf ("s -> %p %zu\n", (void *) s, sizeof (s));
    printf ("s.data -> %p %zu\n", (void *) s->data, sizeof (s->data));
    str_free (s);
    return 0;
}
