#ifndef JCASLIB_TEST_H
#define JCASLIB_TEST_H

#include <err.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define EQ(a, b) (a == b ? 0 : 1)
#define NE(a, b) (a != b ? 0 : 1)
#define LT(a, b) (a < b ? 0 : 1)
#define LE(a, b) (a <= b ? 0 : 1)
#define GT(a, b) (a > b ? 0 : 1)
#define GE(a, b) (a >= b ? 0 : 1)

typedef struct {
        const char *name;
        int expect;
        int run;
        int failed;
        char **log;
        size_t loglines;
        int fatal_error;
} test_T;

extern test_T * t_start (const char *name, int expect);
extern int t_end (test_T *t);
extern void t_log (test_T *t, const char *fmt, ...);
extern void t_check (test_T *t, int status, const char *errmsg);
extern void t_fatal (test_T *t, int status, const char *errmsg);

#endif /* JCASLIB_TEST_H */
