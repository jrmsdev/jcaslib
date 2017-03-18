#include <jclib/db.h>

str_type *
db_fetch (DBM *db, const char *key)
{
    datum *_key = _datum_alloc (key);
    datum _val = dbm_fetch (db, *_key);
    if (_val.dptr == NULL)
    {
        _datum_free (_key);
        return (NULL);
    }
    str_type *val = str_alloc();
    str_nset (val, _val.dptr, _val.dsize);
    _datum_free (_key);
    _datum_free (&_val);
    return (val);
}
