#include "../lib/lib/xmalloc.c"
#include "../lib/lib/xrealloc.c"
#include "../lib/str/str_alloc.c"
#include "../lib/str/str_realloc.c"
#include "../lib/str/str_free.c"
#include "../lib/str/str_set.c"
#include "../lib/str/str_nset.c"
#include "test.h"


void
str_nset_t (void)
{
    t_start ("str_nset");
    str_type *s = str_alloc ();

    str_nset (s, "TEST", 4);
    t_log ("str1 len: %zu", str_len (s));
    t_log ("str1: %s", str_get (s));
    t_check (EQ (str_len (s), 4), "str1 len != 4");
    t_check (strcmp (str_get (s), "TEST"), "str1 != TEST");

    /* check that a second call overrides the str content */
    str_nset (s, "TEST", 4);
    t_log ("str2 len: %zu", str_len (s));
    t_log ("str2: %s", str_get (s));
    t_check (EQ (str_len (s), 4), "str2 len != 4");
    t_check (strcmp (str_get (s), "TEST"), "str2 != TEST");

    str_free (s);
    t_end ("str_nset");
}


void
str_set_t (void)
{
    t_start ("str_set");
    str_type *s = str_alloc ();

    str_set (s, "TEST");
    t_log ("str len: %zu", str_len (s));
    t_log ("str: %s", str_get (s));
    t_check (EQ (str_len (s), 4), "str len != 4");
    t_check (strcmp (str_get (s), "TEST"), "str != TEST");

    str_free (s);
    t_end ("str_set");
}


int
main (void)
{
    str_nset_t ();
    str_set_t ();
    return (0);
}
