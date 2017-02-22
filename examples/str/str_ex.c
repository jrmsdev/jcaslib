#include <jclib/str.h>
#include <stdio.h>

int main (void)
{
    str_type *s = str_alloc ();

    str_set (s, "lalala");
    printf ("s: %s - %zu - %zu\n", str_get (s), s->len, s->allocated);

    for (size_t i = 0; i < s->allocated; i++)
    {
        if (s->data[i] == '\0')
        {
            printf ("%zu: NULL\n", i);
        }
        else
        {
            printf ("%zu: %c\n", i, s->data[i]);
        }
    }

    str_free (s);
    return 0;
}
