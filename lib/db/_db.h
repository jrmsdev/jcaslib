#ifndef JCASLIB_DB__DB_H
#define JCASLIB_DB__DB_H

DBM * _db_open (const char *fname, int flags);
char * _db_fetch (DBM *db, const char *key);
int _db_store (DBM *db, const char *key, const char *val, int flags);
void _db_init (DBM *db);
void _db_updated ();

#endif /* JCASLIB_DB__DB_H */
