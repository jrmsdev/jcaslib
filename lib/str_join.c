#include <jclib/str.h>
#include <jclib/lib.h>

char * str_join (size_t count, const char *sep, const char *str, ...)
{
    va_list ap;
    size_t allocated = STR_ALLOC;
    size_t seplen = strlen (sep);

    DEBUG && printf("allocated: %zu\n", allocated);
    DEBUG && printf("seplen: %zu\n", seplen);

    char *r = (char *) xmalloc (STR_ALLOC);

    size_t idx = 0;
    size_t rlen = 0;

    va_start (ap, str);

    for (const char * s = str; idx < count; s = va_arg (ap, char *), idx++)
    {
        size_t slen = strlen (s);
        DEBUG && printf("idx:%zu - rlen:%zu - slen:%zu\n", idx, rlen, slen);
        DEBUG && printf("s: %s\n", s);

        /* add string */
        size_t addlen = seplen + slen;
        char *adds = xmalloc (addlen);
        if (rlen == 0)
        {
            /* avoid adding separator at init of the string */
            free (adds);
            addlen = slen;
            adds = xmalloc (addlen);
            memset (adds, 0, addlen);
            memcpy (adds, s, slen);
        }
        else
        {
            memset (adds, 0, addlen);
            memcpy (adds, sep, seplen);
            memcpy (adds + seplen, s, slen);
        }

        /* realloc if needed */
        for (; rlen + addlen >= allocated; allocated += STR_ALLOC)
        {
            //~ char *newr = xrealloc (r, (allocated + STR_ALLOC));
            //~ memset (newr + rlen, 0, (allocated - rlen));
            //~ r = newr;
            //~ free (newr);
            char *newr = xmalloc (allocated + STR_ALLOC);
            memcpy (newr, r, rlen);
            free (r);
            r = newr;
            free (newr);
        }

        memcpy (r + rlen, adds, addlen);
        free (adds);
        rlen += addlen;
        DEBUG && printf("rlen2:%zu - addlen:%zu\n", rlen, addlen);
    }

    va_end (ap);

    //~ /* return the needed alloacted memory */
    //~ char *newr = malloc (rlen);
    //~ memcpy(newr, r, rlen);

    //~ free(r);
    //~ return (newr);

    DEBUG && printf("str_join: %s\n\n", r);
    return (r);
}
