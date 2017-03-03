#include "../lib/lib.c"
#include "str_alloc.c"
#include "str_free.c"
#include "../../tests/test.h"


void
str_alloc_t (void)
{
    str_type *s = str_alloc ();

    printf ("str_alloc: sizeof -> %zu\n", sizeof (*s));
    t_check (EQ (sizeof (*s), 24), "str_alloc: sizeof != 24");

    printf ("str_alloc: STR_ALLOC -> %d\n", STR_ALLOC);
    printf ("str_alloc: allocated -> %zu\n", s->allocated);
    t_check (EQ (s->allocated, STR_ALLOC), "str_alloc: allocated != STR_ALLOC");

    printf ("str_alloc: str_len -> %zu\n", str_len (s));
    t_check (EQ (str_len (s), 0), "str_alloc: str_len != 0");

    str_free (s);
}


int
main (void)
{
    str_alloc_t ();
    return (0);
}
