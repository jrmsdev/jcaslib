#include "../lib/log/log.c"
#include "../lib/log/log_exit.c"
#include "../lib/lib/xmalloc.c"
#include "../lib/lib/xrealloc.c"
#include "../lib/str/str_alloc.c"
#include "../lib/str/str_realloc.c"
#include "../lib/str/str_free.c"
#include "../lib/str/str_set.c"
#include "../lib/str/str_nset.c"
#include <jcaslib/test.h>


void
str_nset_t (test_suite_T *ts)
{
    test_T *t = t_start (ts, "str_nset", 4);
    str_type *s = str_alloc ();

    str_nset (s, "TEST", 4);
    t_log (t, "str1 len: %zu", str_len (s));
    t_log (t, "str1: %s", str_get (s));
    t_check (t, EQ (str_len (s), 4), "str1 len != 4");
    t_check (t, strcmp (str_get (s), "TEST"), "str1 != TEST");

    /* check that a second call overrides the str content */
    str_nset (s, "TEST", 4);
    t_log (t, "str2 len: %zu", str_len (s));
    t_log (t, "str2: %s", str_get (s));
    t_check (t, EQ (str_len (s), 4), "str2 len != 4");
    t_check (t, strcmp (str_get (s), "TEST"), "str2 != TEST");

    str_free (s);
    t_end (t);
}


void
str_set_t (test_suite_T *ts)
{
    test_T *t = t_start (ts, "str_set", 2);
    str_type *s = str_alloc ();

    str_set (s, "TEST");
    t_log (t, "str len: %zu", str_len (s));
    t_log (t, "str: %s", str_get (s));

    t_check (t, EQ (str_len (s), 4), "str len != 4");
    t_check (t, strcmp (str_get (s), "TEST"), "str != TEST");

    str_free (s);
    t_end (t);
}


int
main (int argc, char *argv[])
{
    if (argc < 0)
        errx (1, "ERROR: argc < 0???");
    test_suite_T *ts = tsuite_start (argv[0]);
    str_nset_t (ts);
    str_set_t (ts);
    return (tsuite_end (ts));
}
