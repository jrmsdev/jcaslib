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
str_ncat_t (test_suite_T *ts)
{
    test_T *t = t_start (ts, "str_ncat", 1);
    str_type *s = str_alloc ();
    t_log (t, "str len0: %zu", str_len (s));

    str_ncat (s, "TEST", 4);
    t_log (t, "str len: %zu", str_len (s));
    t_check (t, EQ (str_len (s), 4), "str len != 4");

    str_free (s);
    t_end (t);
}


void
str_cat_t (test_suite_T *ts)
{
    test_T *t = t_start (ts, "str_cat", 2);
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
main (int argc, char *argv[])
{
    if (argc < 0)
        errx (1, "ERROR: argc < 0???");
    test_suite_T *ts = tsuite_start (argv[0]);
    str_ncat_t (ts);
    str_cat_t (ts);
    return (tsuite_end (ts));
}
