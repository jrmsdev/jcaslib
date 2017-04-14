#include <jcaslib/test.h>

void
t_end (test_T *t)
{
    free (t);
    t = NULL;
}
