#include <jclib/db.h>
#include <stdlib.h>

char *
db_fetch (DBM *db, const char *key)
{
    datum _key;
    _key.dptr = (void *) key;
    _key.dsize = strlen (key) + 1;

    datum val = dbm_fetch (db, _key);
    if (val.dptr == NULL)
        return (NULL);

    return ((char *) val.dptr);
}
