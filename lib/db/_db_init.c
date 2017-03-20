#include <jclib/db.h>
#include <jclib/log.h>
#include <stdlib.h>
#include <time.h>

#define DB_INIT_KEY DB_KEY_PREFIX"init"
#define DB_VERSION_KEY DB_KEY_PREFIX"version"

void
_db_init (DBM *db)
{
    char *val = db_fetch (db, DB_INIT_KEY);
    if (val == NULL)
    {
        time_t init_t = time (NULL);
        if (init_t == -1)
            log_exit (1, "could not get current epoch");
        char *init_s;
        asprintf (&init_s, "%ld", init_t);
        db_insert (db, DB_INIT_KEY, init_s);
        free (init_s);
    }

    val = NULL;
    val = db_fetch (db, DB_VERSION_KEY);
    if (val == NULL)
    {
        char version[9];
        snprintf (version, 9, "%d", DB_VERSION);
        db_insert (db, DB_VERSION_KEY, version);
    }
}
