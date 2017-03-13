#ifndef JCLIB_DB_H
#define JCLIB_DB_H

#ifdef USE_GDBM
#  include <gdbm-ndbm.h>
#else
#  include <ndbm.h>
#endif

extern DBM * db_openfile (const char *filename);

#endif /* JCLIB_DB_H */
