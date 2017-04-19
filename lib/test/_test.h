#ifndef JCASLIB_TEST___T_LOG_H
#define JCASLIB_TEST___T_LOG_H

void _tprint (test_T *t, const char *tag, const char *fmt, va_list ap);

void _tfail (test_T *t, const char *fmt, ...);
void _tinfo (test_T *t, const char *fmt, ...);

#endif /* JCASLIB_TEST___T_LOG_H */
