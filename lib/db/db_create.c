#include <jcaslib/db.h>
#include <jcaslib/log.h>
#include <fcntl.h>
#include <stdlib.h>

DBM *
db_create (const char *fname)
{
    /* TODO: check db does not already exists */
    DBM *db = _db_open (fname, O_CREAT | O_SYNC | O_RDWR);
    if (db == NULL)
        log_exit (1, "could not create db: %s", fname);
    _db_init (db);
    return (db);
}
