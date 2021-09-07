
//   #include <stdint.h>
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

static const char *
get_FieldDescriptorLabel( const ::google::protobuf::FieldDescriptorProto & proto ) {
    if ( proto.has_label() == false )  return "";
    using namespace ::google::protobuf;
    const FieldDescriptorProto::Label & _label = proto.label();
    if ( _label == FieldDescriptorProto::LABEL_OPTIONAL )  return "optional";
    if ( _label == FieldDescriptorProto::LABEL_REQUIRED )  return "required";
    if ( _label == FieldDescriptorProto::LABEL_REPEATED )  return "repeated";
    return "";
}

static const char *
get_FieldDescriptorType( const ::google::protobuf::FieldDescriptorProto & proto ) {
    if ( proto.has_type() == false )  return "NONE";
    using namespace ::google::protobuf;
    const FieldDescriptorProto::Type & _type = proto.type();
    if ( _type == FieldDescriptorProto::TYPE_DOUBLE   )  return "double";
    if ( _type == FieldDescriptorProto::TYPE_FLOAT    )  return "float";
    if ( _type == FieldDescriptorProto::TYPE_INT64    )  return "int64";
    if ( _type == FieldDescriptorProto::TYPE_UINT64   )  return "uint64";
    if ( _type == FieldDescriptorProto::TYPE_INT32    )  return "int32";
    if ( _type == FieldDescriptorProto::TYPE_FIXED64  )  return "fixed64";
    if ( _type == FieldDescriptorProto::TYPE_FIXED32  )  return "fixed32";
    if ( _type == FieldDescriptorProto::TYPE_BOOL     )  return "bool";
    if ( _type == FieldDescriptorProto::TYPE_STRING   )  return "string";
    if ( _type == FieldDescriptorProto::TYPE_GROUP    )  return "group";
    if ( _type == FieldDescriptorProto::TYPE_BYTES    )  return "bytes";
    if ( _type == FieldDescriptorProto::TYPE_UINT32   )  return "uint32";
    if ( _type == FieldDescriptorProto::TYPE_ENUM     )  return "enum";
    if ( _type == FieldDescriptorProto::TYPE_SFIXED32 )  return "sfixed32";
    if ( _type == FieldDescriptorProto::TYPE_SFIXED64 )  return "sfixed64";
    if ( _type == FieldDescriptorProto::TYPE_SINT32   )  return "sint32";
    if ( _type == FieldDescriptorProto::TYPE_SINT64   )  return "sint64";
    if ( _type == FieldDescriptorProto::TYPE_MESSAGE  ) {
        if ( proto.has_type_name() ) {
            return proto.type_name().c_str();
        }
        return "message";
    }
    return "UNKNOWN";
}

/*
 * looks like:
 *   optional bool server_streaming = 6 [default = false];
 */
static void
dump_FieldDescriptorProto( const ::google::protobuf::FieldDescriptorProto & proto ) {
    const char *label     = get_FieldDescriptorLabel( proto );
    const char *type_name = get_FieldDescriptorType( proto );

    const char *name = "UNKNOWN";
    int number = -1;
    if ( proto.has_name() ) {
        name = proto.name().c_str();
    }
    if ( proto.has_number() ) {
        number = proto.number();
    }
    printf( "    %s %s %s = %d", label, type_name, name, number );
    if ( proto.has_default_value() ) {
        printf( " [default = %s]", proto.default_value().c_str() );
    }
    printf( ";\n" );

    if ( proto.has_extendee() ) {
        printf( "  extendee: '%s'\n", proto.extendee().c_str() );
    }

    if ( proto.has_options() ) {
        printf( "  has options...\n" );
        const ::google::protobuf::FieldOptions & options = proto.options();
    }

    if ( proto.has_proto3_optional() ) {
        if ( proto.proto3_optional() ) {
            printf( "    proto3: optional\n" );
        }
    }
}

static const char *
get_OptimizeMode( const ::google::protobuf::FileOptions::OptimizeMode & mode ) {
    using namespace ::google::protobuf;
    if ( mode == FileOptions_OptimizeMode_SPEED        )  return "speed";
    if ( mode == FileOptions_OptimizeMode_CODE_SIZE    )  return "code_size";
    if ( mode == FileOptions_OptimizeMode_LITE_RUNTIME )  return "lite_runtime";
    return "UNKNOWN";
}

/*
 * This dumps the message type...
 */
static void
dump_DescriptorProto( const ::google::protobuf::DescriptorProto & proto ) {
    if ( proto.has_name() ) {
        printf( "message %s {  ", proto.name().c_str() );
    }

    int count = proto.field_size();
    printf( "//  fields: %d\n", count );
    for ( int i = 0 ; i < count ; i++ ) {
        const ::google::protobuf::FieldDescriptorProto field =
            proto.field( i );
        dump_FieldDescriptorProto( field );
    }

    count = proto.extension_size();
    printf( "    //  extensions: %d\n", count );
    for ( int i = 0 ; i < count ; i++ ) {
        const ::google::protobuf::FieldDescriptorProto extension =
            proto.extension( i );
        printf( "extension...\n" );
    }

    count = proto.nested_type_size();
    printf( "    //  nested_types: %d\n", count );
    for ( int i = 0 ; i < count ; i++ ) {
        const ::google::protobuf::DescriptorProto nested_type =
            proto.nested_type( i );
        printf( "nested type...\n" );
        dump_DescriptorProto( nested_type );
    }

    // ADD THE REST !!
    printf( "}\n" ); // end of message def
}

static void
dump_EnumDescriptorProto( const ::google::protobuf::EnumDescriptorProto & proto ) {
    printf( "enum DESCRIP PROTO\n" );
}

static void
dump_UninterpretedOption( const ::google::protobuf::UninterpretedOption & option ) {
    printf( "    unintepreted options\n" );

    int count = option.name_size();
    printf( "      names: %d\n", count );
    for ( int i = 0 ; i < count ; i++ ) {
        const ::google::protobuf::UninterpretedOption::NamePart pair =
            option.name( i );
        const std::string name = pair.name_part();
        printf( "option  %s\n", name.c_str() );
        // dump_UninterpretedOption( option );
    }

    if ( option.has_identifier_value() ) {
        const std::string & identifier_value = option.identifier_value();
        printf( "  identifier value: '%s'\n", identifier_value.c_str() );
    }

    if ( option.has_positive_int_value() ) {
        const uint64_t positive_int_value = option.positive_int_value();
        printf( "  positive int value: '%d'\n", positive_int_value );
    }

    if ( option.has_negative_int_value() ) {
        const int64_t negative_int_value = option.negative_int_value();
        printf( "  negative int value: '%d'\n", negative_int_value );
    }

    if ( option.has_double_value() ) {
        const double double_value = option.double_value();
        printf( "  double value: '%g'\n", double_value );
    }

    if ( option.has_string_value() ) {
        const std::string & string_value = option.string_value();
        printf( "  string value: '%g'\n", string_value.c_str() );
    }

    if ( option.has_aggregate_value() ) {
        const std::string & aggregate_value = option.aggregate_value();
        printf( "  aggregate value: '%s'\n", aggregate_value.c_str() );
    }

}

static void
dump_ServiceOptions( const ::google::protobuf::ServiceOptions & options ) {
    if ( options.has_deprecated() ) {
        if ( options.deprecated() ) {
            printf( "    options: deprecated\n" );
        }
    }

    int count = options.uninterpreted_option_size();
    printf( "    unintepreted options: %d\n", count );
    for ( int i = 0 ; i < count ; i++ ) {
        const ::google::protobuf::UninterpretedOption option =
            options.uninterpreted_option( i );
        dump_UninterpretedOption( option );
    }

    // extensions ?
}

static void
dump_MethodOptions( const ::google::protobuf::MethodOptions & options ) {
    if ( options.has_deprecated() ) {
        if ( options.deprecated() ) {
            printf( "    options: deprecated\n" );
        }
    }
    if ( options.has_idempotency_level() ) {
        const ::google::protobuf::MethodOptions::IdempotencyLevel & level =
            options.idempotency_level();
    }

    int count = options.uninterpreted_option_size();
    printf( "    unintepreted options: %d\n", count );
    for ( int i = 0 ; i < count ; i++ ) {
        const ::google::protobuf::UninterpretedOption option =
            options.uninterpreted_option( i );
        dump_UninterpretedOption( option );
    }
}

static void
dump_MethodDescriptor( const ::google::protobuf::MethodDescriptorProto & proto ) {
    printf( "Method...\n" );
    if ( proto.has_name() ) {
        printf( "  name: '%s'\n", proto.name().c_str() );
    }
    if ( proto.has_input_type() ) {
        printf( "  input_type: '%s'\n", proto.input_type().c_str() );
    }
    if ( proto.has_output_type() ) {
        printf( "  output_type: '%s'\n", proto.output_type().c_str() );
    }

    if ( proto.has_options() ) {
        const ::google::protobuf::MethodOptions & options = proto.options();
        dump_MethodOptions( options );
    }

    if ( proto.has_client_streaming() ) {
        if ( proto.client_streaming() ) {
            printf( "   client_streaming" );
        }
    }
    if ( proto.has_server_streaming() ) {
        if ( proto.server_streaming() ) {
            printf( "   server_streaming" );
        }
    }
    printf( "\n" );
}

static void
dump_ServiceDescriptorProto( const ::google::protobuf::ServiceDescriptorProto & proto ) {
    printf( "service descriptor\n" );

    if ( proto.has_name() ) {
        printf( "  proto name: '%s'\n", proto.name().c_str() );
    }

    int count = proto.method_size();
    printf( "    methods: %d\n", count );
    for ( int i = 0 ; i < count ; i++ ) {
        const ::google::protobuf::MethodDescriptorProto method =
            proto.method( i );
        dump_MethodDescriptor( method );
    }

    if ( proto.has_options() ) {
        const ::google::protobuf::ServiceOptions & options = proto.options();
        dump_ServiceOptions( options );
    }

}

static void
dump_FileOptions( const ::google::protobuf::FileOptions & options ) {
    if ( options.has_go_package() ) {
        printf( "option go_package = \"%s\";\n", options.go_package().c_str() );
    }

    if ( options.has_java_package() ) {
        printf( "option java_package = \"%s\";\n", options.java_package().c_str() );
    }

    if ( options.has_java_outer_classname() ) {
        printf( "option java_outer_classname = \"%s\";\n",
                options.java_outer_classname().c_str() );
    }

    if ( options.has_java_multiple_files() ) {
        printf( "option java_multiple_files = \"%s\";\n",
                options.java_multiple_files() ? "true" : "false" );
    }

    if ( options.has_java_generate_equals_and_hash() ) {
        printf( "option java_generate_equals_and_hash = \"%s\";\n",
                options.java_generate_equals_and_hash() ? "true" : "false" );
    }

    if ( options.has_java_string_check_utf8() ) {
        printf( "option java_string_check_utf8 = \"%s\";\n",
                options.java_string_check_utf8() ? "true" : "false" );
    }

    if ( options.has_csharp_namespace() ) {
        printf( "option csharp_namespace = \"%s\";\n",
                options.csharp_namespace().c_str() );
    }

    if ( options.has_objc_class_prefix() ) {
        printf( "option objc_class_prefix = \"%s\";\n",
                options.objc_class_prefix().c_str() );
    }

    if ( options.has_php_class_prefix() ) {
        printf( "option php_class_prefix = \"%s\";\n",
                options.php_class_prefix().c_str() );
    }

    if ( options.has_php_namespace() ) {
        printf( "option php_namespace = \"%s\";\n",
                options.php_namespace().c_str() );
    }

    if ( options.has_php_metadata_namespace() ) {
        printf( "option php_metadata_namespace = \"%s\";\n",
                options.php_metadata_namespace().c_str() );
    }

    if ( options.has_swift_prefix() ) {
        printf( "option swift_prefix = \"%s\";\n",
                options.swift_prefix().c_str() );
    }

    if ( options.has_ruby_package() ) {
        printf( "option ruby_package = \"%s\";\n",
                options.ruby_package().c_str() );
    }

    if ( options.has_cc_enable_arenas() ) {
        printf( "option cc_enable_arenas = \"%s\";\n",
                options.cc_enable_arenas() ? "true" : "false" );
    }

    if ( options.has_optimize_for() ) {
        printf( "option optimize_for = \"%s\";\n",
                get_OptimizeMode(options.optimize_for()) );
    }

    if ( options.has_cc_generic_services() ) {
        printf( "option cc_generic_services = \"%s\";\n",
                options.cc_generic_services() ? "true" : "false" );
    }

    if ( options.has_java_generic_services() ) {
        printf( "option java_generic_services = \"%s\";\n",
                options.java_generic_services() ? "true" : "false" );
    }

    if ( options.has_py_generic_services() ) {
        printf( "option py_generic_services = \"%s\";\n",
                options.py_generic_services() ? "true" : "false" );
    }

    if ( options.has_php_generic_services() ) {
        printf( "option php_generic_services = \"%s\";\n",
                options.php_generic_services() ? "true" : "false" );
    }

    if ( options.has_deprecated() ) {
        printf( "option deprecated = \"%s\";\n",
                options.deprecated() ? "true" : "false" );
    }

    int count = options.uninterpreted_option_size();
    printf( "uninterpreted options: %d\n", count );
    for ( int j = 0 ; j < count ; j++ ) {
        const ::google::protobuf::UninterpretedOption & option =
            options.uninterpreted_option( j );
        dump_UninterpretedOption( option );
    }

}

static void
dump_Location( const ::google::protobuf::SourceCodeInfo::Location & location ) {

    int count = location.path_size();
    printf( "paths: %d\n", count );
    printf( "  path: " );
    for ( int j = 0 ; j < count ; j++ ) {
        const int32_t & path = location.path( j );
        printf( "%d ", path );
        // out?
    }
    printf( "\n" );

    count = location.span_size();
    printf( "spans: %d\n", count );
    printf( "  span: " );
    for ( int j = 0 ; j < count ; j++ ) {
        const int32_t & span = location.span( j );
        printf( "%d ", span );
        // out?
    }
    printf( "\n" );

    if ( location.has_leading_comments() ) {
        const std::string & leading_comments = location.leading_comments();
        printf( "/*L\n%s*/\n", leading_comments.c_str() );
    }

    if ( location.has_trailing_comments() ) {
        const std::string & trailing_comments = location.trailing_comments();
        printf( "/*T\n%s*/\n", trailing_comments.c_str() );
    }

    count = location.leading_detached_comments_size();
    for ( int j = 0 ; j < count ; j++ ) {
        const std::string & detached_comments = location.leading_detached_comments( j );
        printf( "/*D\n%s*/\n", detached_comments.c_str() );
    }
}

static void
dump_SourceCodeInfo( const ::google::protobuf::SourceCodeInfo & info ) {
    printf( "SRC CODE INFO\n" );

    int count = info.location_size();
    printf( "locations: %d\n", count );
    for ( int j = 0 ; j < count ; j++ ) {
        const ::google::protobuf::SourceCodeInfo::Location & location =
            info.location( j );
        dump_Location( location );
    }
}

static void
dump_descriptor( const ::google::protobuf::FileDescriptorProto & descriptor ) {
    if ( descriptor.has_name() ) {
        printf( "  name: '%s'\n", descriptor.name().c_str() );
    }
    if ( descriptor.has_package() ) {
        printf( "package %s;\n", descriptor.package().c_str() );
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
    // weak_depenedency

    if ( descriptor.has_options() ) {
        const ::google::protobuf::FileOptions & options = descriptor.options();
        dump_FileOptions( options );
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

    if ( descriptor.has_source_code_info() ) {
        const ::google::protobuf::SourceCodeInfo & info = descriptor.source_code_info();
        dump_SourceCodeInfo( info );
    }

    // add this to the top !
    if ( descriptor.has_syntax() ) {
        const std::string & syntax = descriptor.syntax();
        printf( "  descriptor syntax: '%s'\n", syntax.c_str() );
    }

}

static void
dump_message( ::google::protobuf::compiler::CodeGeneratorRequest & message ) {
    int count = message.file_to_generate_size();
    printf ( "// %d files...\n", count );
    for ( int i = 0 ; i < count ; i++ ) {
        const std::string & s = message.file_to_generate(i);
        printf( "// file_to_generate '%s'\n", s.c_str() );
    }
    //printf( "message '%s'\n", message.file_to_generate().c_str() );
    if ( message.has_parameter() ) {
        printf( "// parameter: '%s'\n", message.parameter().c_str() );
    }
    count = message.proto_file_size();
    printf ( "// %d descriptors...\n", count );
    for ( int i = 0 ; i < count ; i++ ) {
        const ::google::protobuf::FileDescriptorProto &descriptor = message.proto_file( i );
        dump_descriptor( descriptor );
    }
}

int main( int argc, char **argv ) {
    char buffer[ 1024 * 1024 ];
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
