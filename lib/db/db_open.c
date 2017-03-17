#include <jclib/db.h>
#include <fcntl.h>
#include <stdlib.h>

int oflags = O_CREAT | O_SYNC | O_RDWR;
int omode = 0640;

DB *
db_open (const char *fname)
{
	return (dbopen (fname, oflags, omode, DB_BTREE, NULL));
}
