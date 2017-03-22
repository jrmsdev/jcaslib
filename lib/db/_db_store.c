#include <jcaslib/db.h>
#include <jcaslib/log.h>

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
