#include "../lib/log/log.c"
#include "../lib/log/log_exit.c"
#include "../lib/lib/xmalloc.c"
#include "../lib/lib/xrealloc.c"
#include "../lib/str/str_alloc.c"
#include "../lib/str/str_realloc.c"
#include "../lib/str/str_free.c"
#include "../lib/str/str_cat.c"
#include "../lib/str/str_ncat.c"
#include <jcaslib/test.h>


void
str_ncat_t (void)
{
    test_T *t = t_start ("str_ncat", 1);
    str_type *s = str_alloc ();
    t_log (t, "str len0: %zu", str_len (s));

    str_ncat (s, "TEST", 4);
    t_log (t, "str len: %zu", str_len (s));
    t_check (t, EQ (str_len (s), 4), "str len != 4");

    str_free (s);
    t_end (t);
}


void
str_cat_t (void)
{
    test_T *t = t_start ("str_cat", 2);
    str_type *s = str_alloc ();
    t_log (t, "str len0: %zu", str_len (s));

    str_cat (s, "TEST");
    str_cat (s, "TEST");
    t_log (t, "str len: %zu", str_len (s));
    t_check (t, EQ (str_len (s), 8), "str len != 8");
    t_check (t, strcmp (str_get (s), "TESTTEST"), "str != TESTTEST");

    str_free (s);
    t_end (t);
}


int
main (void)
{
    str_ncat_t ();
    str_cat_t ();
    return (0);
}
