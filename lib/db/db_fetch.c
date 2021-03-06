#include <jcaslib/db.h>
#include <stdlib.h>
#include "_db.h"

char *
db_fetch (DBM *db, const char *key)
{
    /* TODO: we should validate keys here */
    return (_db_fetch (db, key));
}

char *
_db_fetch (DBM *db, const char *key)
{
    datum _key;
    _key.dptr = (void *) key;
    _key.dsize = strlen (key) + 1;

    datum val = dbm_fetch (db, _key);
    if (val.dptr == NULL)
        return (NULL);

    return ((char *) val.dptr);
}
