#include "jcasdb.h"
#include <string.h>

int
usage (char *prog)
{
    log_print ("usage: %s [-h] command dbfile [command args]", prog);
    return (1);
}
