#ifndef JCLIB_DB_H
#define JCLIB_DB_H

/*
 * uselib.dbm.h file is created using 'make configure'
 * by default ndbm.h is preferred, we try gdbm.h otherwise
 */
#include <jclib/uselib.dbm.h>

extern DBM * db_openfile (const char *filename);

#endif /* JCLIB_DB_H */
