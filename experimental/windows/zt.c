#include <windows.h>
#include <stdio.h>

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ZwQuerySystemTime( NULL );
    printf( "hello world\n" );
    return 0;
}
