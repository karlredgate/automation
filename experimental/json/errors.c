
#include <stdio.h>
#include <stdlib.h>

void die() { exit( 1 ); }

void
unterminated_string() {
    fprintf( stderr, "unterminated string\n" );
    die();
}

int
invalid_character( int c ) {
    fprintf( stderr, "invalid character in input '%c'n", c );
    die();
    return 0;
}

int
parse_error( char *where ) {
    fprintf( stderr, "parse error (%s)\n", where );
    die();
    return 0;
}

/* vim: set autoindent expandtab sw=4 : */
