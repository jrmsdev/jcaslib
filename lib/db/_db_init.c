#include <jcaslib/db.h>
#include <jcaslib/log.h>
#include <stdlib.h>
#include <time.h>

void
_db_init (DBM *db)
{
    char *val = db_fetch (db, DB_INIT_KEY);
    if (val == NULL)
    {
        time_t init_t = time (NULL);
        if (init_t == -1)
            log_exit (1, "could not get current epoch");
        char init_s[11];
        snprintf (init_s, 11, "%ld", init_t);
        _db_store (db, DB_INIT_KEY, init_s, DBM_REPLACE);
    }
    val = NULL;
    val = db_fetch (db, DB_VERSION_KEY);
    if (val == NULL)
    {
        char version[9];
        snprintf (version, 9, "%d", DB_VERSION);
        _db_store (db, DB_VERSION_KEY, version, DBM_REPLACE);
    }
}
