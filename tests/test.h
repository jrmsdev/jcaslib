#ifndef JCLIB_TEST_H
#define JCLIB_TEST_H

#define EQ(a, b) (a == b ? 0 : 1)
#define NE(a, b) (a != b ? 0 : 1)
#define LT(a, b) (a < b ? 0 : 1)
#define LE(a, b) (a <= b ? 0 : 1)
#define GT(a, b) (a > b ? 0 : 1)
#define GE(a, b) (a >= b ? 0 : 1)

extern void t_start (const char *name);
extern void t_end (const char *name);
extern void t_log (const char *fmt, ...);
extern void t_check (int status, const char *errmsg);

#endif /* JCLIB_TEST_H */
