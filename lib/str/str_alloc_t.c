#include "../lib/lib.c"
#include "str_alloc.c"
#include "str_free.c"
#include "../../tests/test.h"


void
str_alloc_t (void)
{
    t_start ("str_alloc");
    str_type *s = str_alloc ();

    t_log ("sizeof -> %zu\n", sizeof (*s));
    t_check (EQ (sizeof (*s), 24), "sizeof != 24");

    t_log ("STR_ALLOC -> %d\n", STR_ALLOC);
    t_log ("allocated -> %zu\n", s->allocated);
    t_check (EQ (s->allocated, STR_ALLOC), "allocated != STR_ALLOC");

    t_log ("str_len -> %zu\n", str_len (s));
    t_check (EQ (str_len (s), 0), "str_len != 0");

    str_free (s);
    t_end ("str_alloc");
}


int
main (void)
{
    str_alloc_t ();
    return (0);
}
