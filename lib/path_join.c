#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <jclib/path.h>
#include <jclib/log.h>

void path_join(path_type dst, size_t count, char *str, ...)
{
    size_t dst_len = 0;
    va_list sl;
    size_t idx = 0;
    size_t slen = 0;
    size_t adds_len = 0;
    char adds[PATH_MAX_LEN];
    size_t sep_len = strlen(PATH_SEP);

    memset(dst, '\0', PATH_MAX_LEN);
    memset(adds, '\0', PATH_MAX_LEN);

    va_start(sl, str);
    for (char *s = str; idx < count; s = va_arg(sl, char *))
    {
        if (dst_len >= PATH_MAX_LEN)
            log_exit(1, "jclib/path PATH_MAX_LEN reached");

        slen = strlen(s);

        if (dst_len == 0)
        {
            memcpy(adds, s, slen);
            adds_len = slen;
        }
        else
        {
            memcpy(adds, PATH_SEP, sep_len);
            memcpy(adds + sep_len, s, slen);
            adds_len = sep_len + slen;
        }
        memcpy(dst + dst_len, adds, adds_len);
        dst_len += adds_len;

        memset(adds, '\0', PATH_MAX_LEN);
        idx++;
    }
    va_end(sl);
}
