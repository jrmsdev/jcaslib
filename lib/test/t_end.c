#include <jcaslib/test.h>

int
t_end (test_T *t)
{
    int stat = t->failed;
    free (t);
    t = NULL;
    return stat;
}
