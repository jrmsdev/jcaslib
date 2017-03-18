#include <jclib/db.h>

char *
db_fetch (DBM *db, const char *key)
{
    datum *_key = _datum_alloc (key);
    datum val = dbm_fetch (db, *_key);
    if (val.dptr == NULL)
    {
        _datum_free (_key);
        return (NULL);
    }
    _datum_free (_key);
    return ((char *) val.dptr);
}
