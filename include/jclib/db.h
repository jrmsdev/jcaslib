#ifndef JCLIB_DB_H
#define JCLIB_DB_H

#include <db.h>

#define DB_INSERT_FLAGS R_NOOVERWRITE
#define DB_UPDATE_FLAGS R_SETCURSOR

DB * db_open (const char *fname);
void db_close (DB *db);
int _db_put (DB *db, const char *key, const char *val, u_int flags);
void db_insert (DB *db, const char *key, const char *val);
void db_update (DB *db, const char *key, const char *val);

DBT * dbt_alloc (const char *str);
void dbt_free (DBT *t);

#endif /* JCLIB_DB_H */
