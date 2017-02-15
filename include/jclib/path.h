#ifndef JCLIB_PATH_H
#define JCLIB_PATH_H

#define PATH_SEP "/"
#define PATH_MAX_LEN 256

typedef char path_type[PATH_MAX_LEN];

extern void path_join(path_type dst, size_t count, char *str, ...);

#endif /* JCLIB_PATH_H */
