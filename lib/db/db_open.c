#include <jcaslib/db.h>
#include <jcaslib/log.h>
#include <fcntl.h>
#include <stdlib.h>
#include "_db.h"

DBM *
db_open (const char *fname)
{
    DBM *db = _db_open (fname, O_SYNC | O_RDWR);
    if (db == NULL)
        log_exit (1, "could not open db: %s", fname);
    /* TODO: check db was initialized properly */
    return (db);
}
