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

    /* remove .run extension (if exists) */
    if (memcmp (".run", &ts->name[ts->namelen - 4], 4) == 0)
        ts->name[ts->namelen - 4] = '\0';

    return (ts);
}
