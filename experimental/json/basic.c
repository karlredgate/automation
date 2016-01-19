
#include <stdio.h>
#include <stdlib.h>

#include "errors.h"
#include "scanner.h"

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
recognized_JSONObject() {
    printf( "JSONObject\n" );
    return 1;
}

int
JSONObject() {
    printf( "trying Object\n" );
    return token('{') && JSONObjectMembers() && required( token('}') ) && recognized_JSONObject();
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
    init_scanner();
    get_next_token();
    JSONText() && required( token(EOI) );
}

int
main( int argc, char **argv ) {
    parse();
    return 0;
}

/* vim: set autoindent expandtab sw=4 : */
