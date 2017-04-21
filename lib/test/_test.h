#ifndef JCASLIB_TEST___T_LOG_H
#define JCASLIB_TEST___T_LOG_H

#define _COLUMS_FORMAT "%.6s %-15s %-15s"

void _tprint (test_T *t, const char *tag, const char *fmt, va_list ap);

void _tfail (test_T *t, const char *fmt, ...);
void _tinfo (test_T *t, const char *fmt, ...);
void _tpass (test_T *t, const char *fmt, ...);

#endif /* JCASLIB_TEST___T_LOG_H */
