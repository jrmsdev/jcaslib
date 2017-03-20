#include <jclib/db.h>
#include <jclib/log.h>
#include <stdlib.h>
#include <time.h>

#define DB_UPDATE_KEY DB_KEY_PREFIX"update"

static void _db_updated ();

int
_db_store (DBM *db, const char *key, const char *val, int flags)
{
    datum _key;
    datum _val;

    _key.dptr = (void *) key;
    _key.dsize = strlen (key) + 1;
    _val.dptr = (void *) val;
    _val.dsize = strlen (val) + 1;

    int stat = dbm_store (db, _key, _val, flags);
    if (stat == -1)
    {
        db_close (db);
        log_exit (1, "dbm store failed");
        /* not reached */
        return (stat);
    }
    else if (stat == 0)
    {
        _db_updated (db);
    }

    return (stat);
}

void
_db_updated (DBM *db)
{
    time_t update_t = time (NULL);
    if (update_t == -1)
        log_exit (1, "could not get current epoch");

    char *update_s;
    asprintf (&update_s, "%ld", update_t);
    db_insert (db, DB_UPDATE_KEY, update_s);
    free (update_s);
}
