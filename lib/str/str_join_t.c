#include "../lib/lib.c"
#include "str_alloc.c"
#include "str_free.c"
#include "str_cat.c"
#include "str_set.c"
#include "str_join.c"
#include "../../tests/test.h"
#include <strings.h>


void
str_join_t (void)
{
    t_start ("str_join");
    str_type *s = str_alloc ();

    str_nset (s, "TEST", 4);
    str_join (s, ".", 4, "T", "E", "S", "T");

    t_log ("str len: %zu", str_len (s));
    t_log ("str: %s", str_get (s));

    t_check (EQ (str_len (s), 12), "str len != 12");
    t_check (strcmp (str_get (s), "TEST.T.E.S.T"), "str != TEST.T.E.S.T");

    str_free (s);
    t_end ("str_join");
}


int
main (void)
{
    str_join_t ();
    return (0);
}
