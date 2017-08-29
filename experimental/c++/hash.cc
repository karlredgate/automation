
#include <functional>
#include <string>

#include <stdio.h>

int main( int argc, char **argv ) {
    std::hash<unsigned int> hasher;
    std::hash<std::string> shasher;

    printf( "hash 0x%lx => 0x%lx\n",
            (unsigned long)0xdeadbeef,
            hasher(0xdeadbeef) );

    std::string s("foobar");
    printf( "hash '%s' => 0x%lx\n", s.c_str(), shasher(s) );
}
// vim: autoindent expandtab sw=4
