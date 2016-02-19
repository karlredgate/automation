
#include <windows.h>
#include <shlwapi.h>
#include <wininet.h>
#include <stdio.h>

static char *
strindex( char *s, char subject ) {
    while ( *s != '\0' ) {
        if ( *s == subject ) return s;
        ++s;
    }
    return NULL;
}

static void
print_segment( char *segment ) {
    for (;;) {
        if ( *segment == '\0' ) return;
        char *space = strindex( segment, ' ' );

        if ( space == NULL ) {
            printf( "%s ", segment );
            return;
        }

        *space = '\0';
        printf( "%s%%20", segment );
        segment = space + 1;
    }
}

static void
print_segments( char *path ) {
    if ( *path == '\\' ) path++;

    printf( "(segments " );

    for (;;) {
        if ( *path == '\0' ) break;
        char *end = strindex(path, '\\');
        if ( end == NULL ) {
            print_segment( path );
            break;
        }
        *end = '\0';
        print_segment( path );
        path = end + 1;
    }

    printf( " ) " );
}

int main(int argc, char **argv) {
    int status, i;
    DWORD size = INTERNET_MAX_URL_LENGTH;

    char path[INTERNET_MAX_URL_LENGTH];
    char url[INTERNET_MAX_URL_LENGTH];

    /* xslt filter the SWRL policy to CLIPS */
    /* generate CLIPS engine and load policy */
    /* read stdin files and add rules to policy */
    /* reset and run policy */

    while ( feof(stdin) == 0 ) {
        if ( fgets(path, INTERNET_MAX_URL_LENGTH, stdin) == NULL ) {
            printf( "error reading <%s>\n", path );
            continue;
        }

        size = INTERNET_MAX_URL_LENGTH;
        HRESULT result = UrlCreateFromPath( path, url, &size, (DWORD)0 );

        switch (result) {
        case E_POINTER: /* passed in a bad pointer */ break;
        }

        if ( result != S_OK ) {
            printf( "err <0x%x> converting <%s>\n", result, path );
            continue;
        }

        printf( "( assert (File (path \"%s\") ", url );

        char *ext = PathFindExtension(path);
        if ( *ext == '.' ) {
            printf( "(extension %s) ", ext+1 );
        }

        print_segments( path );

        printf( ") )\n", url );
    }

    // UrlCreateFromPath( argv[1], url, &size, NULL );
    return 0;
}

/* vim: set autoindent expandtab sw=4: */
