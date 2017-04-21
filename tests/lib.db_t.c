#include "../lib/lib/xmalloc.c"
#include "../lib/lib/xrealloc.c"

#include "../lib/log/log.c"
#include "../lib/log/log_exit.c"
#include "../lib/log/log_warn.c"

#include "../lib/str/str_alloc.c"
#include "../lib/str/str_realloc.c"
#include "../lib/str/str_free.c"
#include "../lib/str/str_nset.c"
#include "../lib/str/str_set.c"
#include "../lib/str/str_array_alloc.c"
#include "../lib/str/str_array_append.c"
#include "../lib/str/str_array_insert.c"
#include "../lib/str/str_array_free.c"
#include "../lib/str/str_array_get.c"
#include "../lib/str/str_array_realloc.c"

#include "../lib/db/_db_init.c"
#include "../lib/db/_db_open.c"
#include "../lib/db/_db_store.c"
#include "../lib/db/_db_updated.c"
#include "../lib/db/db_close.c"
#include "../lib/db/db_create.c"
#include "../lib/db/db_delete.c"
#include "../lib/db/db_fetch.c"
#include "../lib/db/db_fetchall.c"
#include "../lib/db/db_insert.c"
#include "../lib/db/db_open.c"
#include "../lib/db/db_replace.c"
#include "../lib/db/dbdata_free.c"

#include <jcaslib/test.h>


void
fake_t (test_suite_T *ts)
{
    int expect = 1;
    test_T *t = t_start (ts, "fake", expect);

    t_check (t, 0, "");

    t_end (t);
}


int
main (int argc, char *argv[])
{
    if (argc < 1)
        errx (1, "ERROR: argc < 1???");

    int expect = 1;
    test_suite_T *ts = tsuite_start (argv[0], expect);

    fake_t (ts);

    return (tsuite_end (ts));
}
