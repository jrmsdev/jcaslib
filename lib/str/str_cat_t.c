#include "../lib/lib.c"
#include "str_alloc.c"
#include "str_free.c"
#include "str_cat.c"
#include "../../tests/test.h"


void
str_ncat_t (void)
{
    t_start ("str_ncat");
    str_type *s = str_alloc ();
    t_log ("str len0: %zu", str_len (s));

    str_ncat (s, "TEST", 4);
    t_log ("str len: %zu", str_len (s));
    t_check (EQ (str_len (s), 4), "str len != 4");

    str_free (s);
    t_end ("str_ncat");
}


int
main (void)
{
    str_ncat_t ();
    return (0);
}
