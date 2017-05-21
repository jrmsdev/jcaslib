#include <jcaslib/path.h>
#include <jcaslib/test.h>

#include <string.h>


void
path_join_t (test_suite_T *ts)
{
    test_T *t = t_start (ts, "path_join", 2);
    str_type *p = str_alloc (NULL);

    path_join (p, 3, "/path", "join", "test");

    t_log (t, "path len: %zu", str_len (p));
    t_log (t, "path: %s", str_get (p));

    t_check (t, EQ (str_len (p), 15), "path len != 15");
    t_check (t, strcmp (str_get (p), "/path/join/test"), "path != /path/join/test");

    str_free (p);
    t_end (t);
}


int
main (int argc, char *argv[])
{
    if (argc < 1)
        errx (1, "ERROR: argc < 1???");

    int expect = 1;
    test_suite_T *ts = tsuite_start (argv[0], expect);

    path_join_t (ts);

    return (tsuite_end (ts));
}
