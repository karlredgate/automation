
#include <stdio.h>
#include <stdlib.h>

#include "errors.h"

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

/* vim: set autoindent expandtab sw=4 : */
