#include <jcaslib/test.h>
#include <libgen.h>
#include <string.h>

test_suite_T *
tsuite_start (const char *progname)
{
    test_suite_T *ts = (test_suite_T *) malloc (sizeof (test_suite_T));
    if (ts == NULL)
        errx (1, "%s: t_start malloc failed!", progname);

    ts->DEBUG = 0;
    ts->progname = progname;
    ts->failed = 0;
    ts->error = 0;

    ts->name = basename (progname);
    ts->namelen = strlen (ts->name);

    /* remove _t.run from the end of the ts name (if exists) */
    if (memcmp ("_t.run", &ts->name[ts->namelen - 6], 6) == 0)
        ts->name[ts->namelen - 6] = '\0';

    return (ts);
}
