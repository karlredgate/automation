
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int result;
    WSADATA ws_data;

    result = WSAStartup( MAKEWORD(2,2), &ws_data );
    if ( result != 0 ) {
	printf( "WSAStartup failed: %d\n", result );
        return 1;
    }
    return 0;
}

/*
 * vim:autoindent
 */
