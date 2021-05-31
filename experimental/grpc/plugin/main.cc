
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
dump_DescriptorProto( const ::google::protobuf::DescriptorProto & proto ) {
    printf( "DESCRIP PROTO\n" );
    if ( proto.has_name() ) {
        printf( "  proto name: '%s'\n", proto.name().c_str() );
    }
}

static void
dump_EnumDescriptorProto( const ::google::protobuf::EnumDescriptorProto & proto ) {
    printf( "enum DESCRIP PROTO\n" );
}

static void
dump_ServiceOptions( const ::google::protobuf::ServiceOptions & options ) {
}

static void
dump_ServiceDescriptorProto( const ::google::protobuf::ServiceDescriptorProto & proto ) {
    printf( "service DESCRIP PROTO\n" );

    if ( proto.has_name() ) {
        printf( "  proto name: '%s'\n", proto.name().c_str() );
    }

    if ( proto.has_options() ) {
        const ::google::protobuf::ServiceOptions & options = proto.options();
    }

}

static void
dump_FieldDescriptorProto( const ::google::protobuf::FieldDescriptorProto & proto ) {
    printf( "field DESCRIP PROTO\n" );
}

static void
dump_SourceCodeInfo( const ::google::protobuf::SourceCodeInfo & info ) {
    printf( "SRC CODE INFO\n" );
}

static void
dump_descriptor( const ::google::protobuf::FileDescriptorProto & descriptor ) {
    if ( descriptor.has_name() ) {
        printf( "  name: '%s'\n", descriptor.name().c_str() );
    }
    if ( descriptor.has_package() ) {
        printf( "  package: '%s'\n", descriptor.package().c_str() );
    }

    int dependency_count = descriptor.dependency_size();
    printf( "dependencies: %d\n", dependency_count );
    for ( int j = 0 ; j < dependency_count ; j++ ) {
        const std::string dependency = descriptor.dependency( j );
        printf( "  dependency: '%s'\n", dependency.c_str() );
    }

    int public_dependency_count = descriptor.public_dependency_size();
    printf( "public_dependencies: %d\n", dependency_count );
    for ( int j = 0 ; j < public_dependency_count ; j++ ) {
        const int32_t public_dependency = descriptor.public_dependency( j );
        printf( "  public_dependency: '%d'\n", public_dependency );
    }

    int message_type_count = descriptor.message_type_size();
    printf( "message_types: %d\n", message_type_count );
    for ( int j = 0 ; j < message_type_count ; j++ ) {
        const ::google::protobuf::DescriptorProto & message_type =
            descriptor.message_type( j );
        dump_DescriptorProto( message_type );
    }

    int enum_type_count = descriptor.enum_type_size();
    printf( "enum_types: %d\n", enum_type_count );
    for ( int j = 0 ; j < enum_type_count ; j++ ) {
        const ::google::protobuf::EnumDescriptorProto & enum_type =
            descriptor.enum_type( j );
        dump_EnumDescriptorProto( enum_type );
    }

    int service_count = descriptor.service_size();
    printf( "services: %d\n", service_count );
    for ( int j = 0 ; j < service_count ; j++ ) {
        const ::google::protobuf::ServiceDescriptorProto & service =
            descriptor.service( j );
        dump_ServiceDescriptorProto( service );
    }

    int extension_count = descriptor.extension_size();
    printf( "extensions: %d\n", extension_count );
    for ( int j = 0 ; j < extension_count ; j++ ) {
        const ::google::protobuf::FieldDescriptorProto & extension =
            descriptor.extension( j );
        dump_FieldDescriptorProto( extension );
    }

    if ( descriptor.has_options() ) {
        const ::google::protobuf::FileOptions & options = descriptor.options();
    }

    if ( descriptor.has_syntax() ) {
        const std::string & syntax = descriptor.syntax();
        printf( "  descriptor syntax: '%s'\n", syntax.c_str() );
    }

}

static void
dump_message( ::google::protobuf::compiler::CodeGeneratorRequest & message ) {
    int count = message.file_to_generate_size();
    printf ( "%d files...\n", count );
    for ( int i = 0 ; i < count ; i++ ) {
        const std::string & s = message.file_to_generate(i);
        printf( "file '%s'\n", s.c_str() );
    }
    //printf( "message '%s'\n", message.file_to_generate().c_str() );
    if ( message.has_parameter() ) {
        printf( "parameter: '%s'\n", message.parameter().c_str() );
    }
    count = message.proto_file_size();
    printf ( "%d descriptors...\n", count );
    for ( int i = 0 ; i < count ; i++ ) {
        const ::google::protobuf::FileDescriptorProto &descriptor = message.proto_file( i );
        dump_descriptor( descriptor );
    }
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
