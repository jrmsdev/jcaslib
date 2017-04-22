#include "jcasdb.h"
#include <string.h>

int
main (int argc, char *argv[])
{
    log_set_progname (argv[0]);
    if (argc <= 2)
        return (usage (argv[0]));

    int stat = 128;
    if (strcmp (argv[1], "-h") == 0)
    {
        return (usage (argv[0]));
    }
    else
    {
        DBM *db = db_open (argv[2]);
        if (strcmp (argv[1], "info") == 0)
            stat = dbinfo (db);
        db_close (db);
    }
    return (stat);
}
