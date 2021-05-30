
#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "plugin.pb.h"

static size_t
read_buffer( unsigned max_length, char *out ) {
    size_t nread;
    size_t cur_len = 0;
    uint8_t c;
    while ( (nread = fread(out + cur_len, 1, max_length - cur_len, stdin)) != 0 ) {
        cur_len += nread;
        if ( cur_len == max_length ) {
            fprintf(stderr, "max message length exceeded\n");
            exit(1);
        }
    }
    out[cur_len] = '\0';
    return cur_len;
}

static void
dump_message( ::google::protobuf::compiler::CodeGeneratorRequest & message ) {
    printf( "message '%s'\n", message.file_to_generate().c_str() );
}

int main( int argc, char **argv ) {
    char buffer[ 32 * 1024 ];
    size_t length = read_buffer( sizeof buffer, buffer );
    std::string s( buffer, length );
    ::google::protobuf::compiler::CodeGeneratorRequest message;
    message.Clear();

    if ( ! message.ParseFromString(s) ) {
        fprintf( stderr, "Failed to read CodeGeneratorRequest\n" );
    }

    dump_message( message );

    return 0;
}

/* vim: set autoindent expandtab sw=4 : */
