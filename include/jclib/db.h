#ifndef JCLIB_DB_H
#define JCLIB_DB_H

#include <ndbm.h>

extern DBM * db_openfile (const char *filename);

#endif /* JCLIB_DB_H */
