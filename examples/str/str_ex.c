#include <jclib/str.h>
#include <stdio.h>

int main (void)
{
    str_type *s = str_alloc ();

    str_set (s, "lalala");
    printf ("s: %s - %zu - %zu\n", str_get (s), s->len, s->allocated);

    str_cat (s, "lelele");
    printf ("s: %s - %zu - %zu\n", str_get (s), s->len, s->allocated);

    for (size_t i = 0; i < s->allocated; i++)
    {
        if (s->data[i] != '\0')
            printf ("%zu: %c\n", i, s->data[i]);
    }

    str_free (s);

    s = str_alloc();
    str_set (s, "lilili");
    printf ("s: %s - %zu - %zu\n", str_get (s), s->len, s->allocated);

    str_join (s, "/", 5, "la", "le", "li", "lo", "lu");
    printf ("s: %s - %zu - %zu\n", str_get (s), s->len, s->allocated);

    str_free (s);

    return 0;
}
