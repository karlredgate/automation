
#include <stdio.h>
#include <stdlib.h>

#define EOI     256
#define INTEGER 257
#define STRING  258
#define ERROR   259

static int c = 0;
static int current_token;
static char current_identifier[1024];
static char current_string[4096];
static int stringpos;
static long current_integer;

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

char *
report_token( int token ) {
    static char s[4096];

    switch (token) {
    case ':':     return "<:>";
    case ',':     return "<,>";
    case '{':     return "<{>";
    case '}':     return "<}>";
    case '[':     return "<[>";
    case ']':     return "<]>";
    case EOI:     return "<EOI>";
    case INTEGER:
        sprintf( s, "INTEGER<%ld>", current_integer );
        return s;
    case STRING:
        sprintf( s, "STRING<%s>", current_string );
        return s;
    default:
        sprintf( s, "<? %d ?>", token );
        return s;
    }
}

int
nextchar() {
    c = getchar();
    if ( c != EOF ) return 1;
    if ( feof(stdin) ) {
        current_token = EOI;
        return 1;
    }
    return 0;
}

void
get_next_token() {
    int digit;

start_scan:
    switch (c) {
    case EOF:
        current_token = EOI;
        return;
    case ' ':
    case '\t':
    case '\r':
    case '\n': goto eat_whitespace;
    case '"':
        stringpos = 0;
        c = getchar();
        goto recognize_string;
    case '{':
    case '}':
    case '[':
    case ']':
    case ':':
    case ',':
        current_token = c;
        c = getchar();
        return;
    case '0': goto determine_base;
    case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8':
    case '9': goto recognize_decimal;
    default:
        invalid_character( c );
    }

eat_whitespace:
    c = getchar();
    switch (c) {
    case ' ':
    case '\t':
    case '\r':
    case '\n': goto eat_whitespace;
    }
    goto start_scan;

recognize_decimal:
    switch (c) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        current_integer *= 10;
        current_integer += c - '0';
        c = getchar();
        goto recognize_decimal;
    default:
        current_token = INTEGER;
        return;
    }

recognize_hex:
    switch (c) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        digit = c - '0';
        goto add_hex_digit;
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
        digit = (c - 'a') + 10;
        goto add_hex_digit;
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
        digit = (c - 'A') + 10;
        goto add_hex_digit;
    default:
        current_token = INTEGER;
        return;
    }
add_hex_digit:
    current_integer *= 16;
    current_integer += digit;
    c = getchar();
    goto recognize_hex;

recognize_octal:
    switch (c) {
    case '0': case '1': case '2': case '3':
    case '4': case '5': case '6': case '7':
        current_integer *= 8;
        current_integer += c - '0';
        c = getchar();
        goto recognize_octal;
    case '8':
    case '9':
        invalid_character( c );
    default:
        current_token = INTEGER;
        return;
    }

determine_base:
    c = getchar();
    switch (c) {
    case 'x':
        c = getchar();
        goto recognize_hex;
    case '0': case '1': case '2': case '3': case '4': case '5': case '6':
    case '7': goto recognize_octal;
    case '8': case '9':
        invalid_character( c );
    default:
        current_integer = 0;
        current_token = INTEGER;
        return;
    }

recognize_string:
    switch (c) {
    case EOF:
        unterminated_string();
    case '"':
        current_string[stringpos] = '\0';
        c = getchar();
        current_token = STRING;
        return;
    case '\\':
        c = getchar();
        goto recognize_metachar;
    default:
        current_string[stringpos++] = c;
        c = getchar();
        goto recognize_string;
    }

recognize_metachar:
    switch (c) {
    case EOF:
        unterminated_string();
    case '"':
        current_string[stringpos++] = '"';
        c = getchar();
        goto recognize_string;
    case 'n':
        current_string[stringpos++] = '\n';
        c = getchar();
        goto recognize_string;
    case 'r':
        current_string[stringpos++] = '\r';
        c = getchar();
        goto recognize_string;
    case 't':
        current_string[stringpos++] = '\t';
        c = getchar();
        goto recognize_string;
    }

recognize_identifier:
    current_token = ERROR;
    return;
}

int
look_ahead( int _token ) {
    return current_token == _token;
}

int
required( int found ) {
    if ( found == 0 ) parse_error("required");
    return 1;
}

int
token( int _token ) {
    printf( "CHECK TOKEN current %s == %s\n", report_token(current_token), report_token(_token) );
    if ( current_token != _token )  return 0;
    get_next_token();
    printf( "NEXT TOKEN: %s\n", report_token(current_token) );
    return 1;
}

int JSONValue();

int
JSONNumber() {
    return token(INTEGER);
}

int
JSONString() {
    return token(STRING);
}

int
JSONMember() {
    printf( "trying member\n" );
    return JSONString() && required( token(':') ) && required( JSONValue() );
}

int
JSONMemberList() {
    printf( "trying member-list\n" );
    if ( JSONMember() == 0 ) return 0;
    while ( look_ahead(',') ) {
        token(',');
        if ( JSONMember() == 0 ) parse_error("trailing ,");
    }
    return 1;
}

int
JSONObjectMembers() {
    printf( "trying members\n" );
    return JSONMemberList() || 1;
}

int
JSONObject() {
    printf( "trying Object\n" );
    return token('{') && JSONObjectMembers() && required( token('}') );
}

int
JSONValue() {
    printf( "trying Value\n" );
    return JSONObject() || JSONNumber() || JSONString();
}

int
JSONText() {
    return JSONValue() || parse_error("invalid value");
}

void
parse() {
    c = getchar();
    get_next_token();
    JSONText() && required( token(EOI) );
}

int
main( int argc, char **argv ) {
    parse();
}

/* vim: set autoindent expandtab sw=4 : */
