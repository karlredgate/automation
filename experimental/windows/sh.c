
#include <windows.h>
#include <stdio.h>

#include "tcl.h"

int Sh_Init( Tcl_Interp *interp ) {
    int interactive = 1;
    Tcl_Obj *interactive_obj;
    interactive_obj = Tcl_GetVar2Ex( interp, "tcl_interactive", NULL, TCL_GLOBAL_ONLY );
    if ( interactive_obj != NULL ) {
        Tcl_GetIntFromObj( interp, interactive_obj, &interactive );
    }

    if ( interactive ) printf( " ** Sh debug tool v1.0\n" );

    return TCL_OK;
}

int main(int argc, char **argv) {
    Tcl_Main( argc, argv, Sh_Init );
    return 0;
}

/*
 * vim:autoindent
 */
