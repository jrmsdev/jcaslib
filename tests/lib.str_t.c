#include "../lib/log/log.c"
#include "../lib/log/log_exit.c"
#include "../lib/lib/xmalloc.c"
#include "../lib/lib/xrealloc.c"
#include "../lib/str/str_alloc.c"
#include "../lib/str/str_cat.c"
#include "../lib/str/str_free.c"
#include "../lib/str/str_join.c"
#include "../lib/str/str_ncat.c"
#include "../lib/str/str_nset.c"
#include "../lib/str/str_realloc.c"
#include "../lib/str/str_set.c"
#include "../lib/str/str_vjoin.c"
#include <jcaslib/test.h>


void
str_alloc_t (test_suite_T *ts)
{
    test_T *t = t_start (ts, "str_alloc", 3);
    str_type *s = str_alloc ();

    t_log (t, "sizeof -> %zu", sizeof (*s));
    t_check (t, EQ (sizeof (*s), 24), "sizeof != 24");

    t_log (t, "STR_ALLOC -> %d", STR_ALLOC);
    t_log (t, "size -> %zu", str_size (s));
    t_check (t, EQ (str_size (s), STR_ALLOC), "size != STR_ALLOC");

    t_log (t, "str_len -> %zu", str_len (s));
    t_check (t, EQ (str_len (s), 0), "str_len != 0");

    str_free (s);
    t_end (t);
}


void
str_realloc_t (test_suite_T *ts)
{
    test_T *t = t_start (ts, "str_realloc", 3);
    str_type *s = str_alloc ();

    t_log (t, "sizeof -> %zu", sizeof (*s));
    t_check (t, EQ (sizeof (*s), 24), "sizeof != 24");

    t_log (t, "STR_ALLOC -> %d", STR_ALLOC);
    t_log (t, "size -> %zu", str_size (s));
    t_check (t, EQ (str_size (s), STR_ALLOC), "size != STR_ALLOC");

    str_realloc (s);
    t_log (t, "resized -> %zu", str_size (s));
    t_check (t, EQ (str_size (s), (STR_ALLOC * 2)),
                    "resized != (STR_ALLOC * 2)");

    str_free (s);
    t_end (t);
}


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


void
str_join_t (test_suite_T *ts)
{
    test_T *t = t_start (ts, "str_join", 2);
    str_type *s = str_alloc ();

    str_nset (s, "TEST", 4);
    str_join (s, ".", 4, "T", "E", "S", "T");

    t_log (t, "str len: %zu", str_len (s));
    t_log (t, "str: %s", str_get (s));

    t_check (t, EQ (str_len (s), 12), "str len != 12");
    t_check (t, strcmp (str_get (s), "TEST.T.E.S.T"), "str != TEST.T.E.S.T");

    str_free (s);
    t_end (t);
}


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
    if (argc < 1)
        errx (1, "ERROR: argc < 1???");
    test_suite_T *ts = tsuite_start (argv[0]);

    str_alloc_t (ts);
    str_realloc_t (ts);
    str_ncat_t (ts);
    str_cat_t (ts);
    str_join_t (ts);
    str_nset_t (ts);
    str_set_t (ts);

    return (tsuite_end (ts));
}
