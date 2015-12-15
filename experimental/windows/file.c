#include <windows.h>
#include <stdio.h>

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HANDLE h;
    DWORD bytes;

    h = CreateFile( "foo.txt", GENERIC_READ | GENERIC_WRITE,
                    FILE_SHARE_READ, NULL, OPEN_ALWAYS,
		    FILE_ATTRIBUTE_NORMAL, NULL );

    if ( h == INVALID_HANDLE_VALUE ) {
        printf( "Failed to open file\n" );
	exit( 1 );
    }

    WriteFile( h, "Testing\n", 8, &bytes, NULL );
    CloseHandle( h );

    printf( "file written\n" );
    return 0;
}

/*
 * vim:autoindent
 */
