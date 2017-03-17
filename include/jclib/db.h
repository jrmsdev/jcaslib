#ifndef JCLIB_DB_H
#define JCLIB_DB_H

#include <db.h>

DB * db_open (const char *fname);
void db_close (DB *db);
void db_put (DB *db, const char *key, const char *val);

DBT * dbt_alloc (const char *str);
void dbt_free (DBT *t);

#endif /* JCLIB_DB_H */
