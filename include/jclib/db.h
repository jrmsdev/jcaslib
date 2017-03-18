#ifndef JCLIB_DB_H
#define JCLIB_DB_H

#include <jclib/str.h>

#ifdef USE_GDBM
#include <gdbm-ndbm.h>
#else
#include <ndbm.h>
#endif

extern DBM * db_open (const char *fname);
extern void db_close (DBM *db);
extern void db_insert (DBM *db, const char *key, const char *val);
extern void db_replace (DBM *db, const char *key, const char *val);
extern str_type * db_fetch (DBM *db, const char *key);

int _db_store (DBM *db, const char *key, const char *val, int flags);
datum * _datum_alloc (const char *str);
void _datum_free (datum *d);

#endif /* JCLIB_DB_H */
