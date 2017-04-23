#include <jcaslib/db.h>
#include <jcaslib/log.h>
#include "_db.h"

void
db_delete (DBM *db, const char *key)
{
    datum k;
    k.dptr = (void *) key;
    k.dsize = strlen (key) + 1;
    if (dbm_delete (db, k) == -1)
        log_warn ("db delete failed: %s", key);
    _db_updated (db);
}
