#include <jclib/db.h>
#include <jclib/log.h>

void
db_insert (DBM *db, const char *key, const char *val)
{
    int stat = _db_store (db, key, val, DBM_INSERT);
    if (stat == 1)
        log_warn ("db key already exists: '%s'", key);
}
