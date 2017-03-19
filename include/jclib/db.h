#ifndef JCLIB_DB_H
#define JCLIB_DB_H

#ifdef USE_GDBM
#include <gdbm-ndbm.h>
#else
#include <ndbm.h>
#endif

typedef struct {
    char *key;
    char *val;
} dbrec;

typedef struct {
	dbrec **db;
	size_t len;
} dbdata;

extern DBM * db_open (const char *fname);
extern void db_close (DBM *db);
extern void db_insert (DBM *db, const char *key, const char *val);
extern void db_replace (DBM *db, const char *key, const char *val);
extern char * db_fetch (DBM *db, const char *key);
extern dbdata * db_fetchall (DBM *db, const char *kbase);

extern dbdata * dbdata_alloc (size_t len);
extern void dbdata_free (dbdata *dat);

int _db_store (DBM *db, const char *key, const char *val, int flags);

#endif /* JCLIB_DB_H */
