
#include <stdio.h>

typedef int (*ff)(int,int);

// fn is a keyword ??
// fn foo() {
#if 0
ff foo() {
    int i = 20;
    auto f = [&i]( int a, int b ) -> int { return a + b + i; };
    return f;
}
#endif

int main( int argc, char **argv ) {
    printf( "hello\n" );

    auto f = []( int a, int b ) -> int { return a + b; };
    auto n = f( 10, 22 );
    printf( "n = %d\n", n );

    struct LocalClass {
        int operator () ( int a, int b ) const { return a + b; }
    } f2;
    int n2 = f2( 45, 11 );
    printf( "n2 expect 56, actual %d\n", n2 );

    int i3 = 20;
    auto f3 = [&i3]( int a, int b ) -> int { return a + b + i3; };
    auto n3 = f3( 10, 22 );
    printf( "n3 expected 52 actual %d\n", n3 );
}

/* vim: set autoindent expandtab sw=4 : */
