#include <jclib/db.h>

void
db_replace (DBM *db, const char *key, const char *val)
{
    (void) _db_store (db, key, val, DBM_REPLACE);
}
