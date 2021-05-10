
#include <webassembly.h>

typedef unsigned int size_t;

size_t
strlcpy(char *dst, const char *src, size_t siz) {
    char *d = dst;
    const char *s = src;
    size_t n = siz;

    /* Copy as many bytes as will fit */
    if (n != 0) {
        while (--n != 0) {
            if ((*d++ = *s++) == '\0') break;
        }
    }
    /* Not enough room in dst, add NUL and traverse rest of src */
    if (n == 0) {
        if (siz != 0) *d = '\0';                /* NUL-terminate dst */
        while (*s++) ;
    }
    return(s - src - 1);        /* count does not include NUL */
}

size_t
strlcat(char *dst, const char *src, size_t siz) {
    char *d = dst;
    const char *s = src;
    size_t n = siz;
    size_t dlen;

    /* Find the end of dst and adjust bytes left but don't go past end */
    while (n-- != 0 && *d != '\0') d++;
    dlen = d - dst;
    n = siz - dlen;
    if (n == 0) return(dlen + strlen(s));
    while (*s != '\0') {
        if (n != 1) {
            *d++ = *s;
            n--;
        }
        s++;
    }
    *d = '\0';
    return(dlen + (s - src));        /* count does not include NUL */
}

struct botmgr_ak {
    char *sensor_data;
    int ke_cnt, ke_vel;
    int mme_cnt, mduce_cnt, me_vel;
} bmak = {
    NULL, 0, 0, 0, 0, 0
};

export int add( int a, int b ) {
    int x = strcmp( "hello", "goodbye" );
    return a + b;
}

export char * mesg() {
    char *buffer = malloc( 1024 );
    bmak.sensor_data = buffer;

    strlcpy( buffer, "hello", sizeof (buffer) );
    strlcat( buffer, ", cruel world", sizeof (buffer) );
    return buffer;
}

export int start() {
    return 3;
}

/* vim: set autoindent expandtab sw=4 : */
