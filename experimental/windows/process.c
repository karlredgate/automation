
#include <windows.h>

#include "tcl.h"

static int debug = 0;

static HANDLE heap;

/**
 */
static void
Process_delete( ClientData data ) {
    LPPROCESS_INFORMATION *pinfo = (LPPROCESS_INFORMATION *)data;
    HeapFree( heap, 0, pinfo );
}

/**
 */
static int
Process_obj( ClientData data, Tcl_Interp *interp,
             int objc, Tcl_Obj * CONST *objv )
{
    LPPROCESS_INFORMATION *pinfo = (LPPROCESS_INFORMATION *)data;

    if ( objc == 1 ) {
        Tcl_SetObjResult( interp, Tcl_NewLongObj((long)(pinfo)) );
        return TCL_OK;
    }

    char *command = Tcl_GetStringFromObj( objv[1], NULL );
    if ( Tcl_StringMatch(command, "type") ) {
        Tcl_SetResult( interp, "Process", TCL_STATIC );
        return TCL_OK;
    }

    if ( Tcl_StringMatch(command, "send") ) {
        if ( objc != 3 ) {
            Tcl_ResetResult( interp );
            Tcl_WrongNumArgs( interp, 2, objv, "request" );
            return TCL_ERROR;
        }
        /*
        char *request = Tcl_GetStringFromObj( objv[2], NULL );
        channel->send( request );
        */
        Tcl_ResetResult( interp );
        return TCL_OK;
    }

    if ( Tcl_StringMatch(command, "ask") ) {
        if ( objc != 3 ) {
            Tcl_ResetResult( interp );
            Tcl_WrongNumArgs( interp, 2, objv, "request" );
            return TCL_ERROR;
        }
        int result = 0;
        /*
        char *request = Tcl_GetStringFromObj( objv[2], NULL );
        channel->send( request );
        char buffer[1024];
        int result = channel->receive( buffer, sizeof(buffer) );
        Tcl_SetObjResult( interp, Tcl_NewStringObj(buffer, -1) );
        */
        Tcl_SetObjResult( interp, Tcl_NewStringObj("nothing", -1) );
        return result;
    }

    Tcl_SetResult( interp, "Unknown command for Process object", TCL_STATIC );
    return TCL_ERROR;
}

/**
 * WINBASEAPI BOOL WINAPI
 * CreateProcessA(
 *   __in_opt     LPCTSTR lpApplicationName,
 *   __inout_opt  LPTSTR lpCommandLine,
 *   __in_opt     LPSECURITY_ATTRIBUTES lpProcessAttributes,
 *   __in_opt     LPSECURITY_ATTRIBUTES lpThreadAttributes,
 *   __in         BOOL bInheritHandles,
 *   __in         DWORD dwCreationFlags,
 *   __in_opt     LPVOID lpEnvironment,
 *   __in_opt     LPCTSTR lpCurrentDirectory,
 *   __in         LPSTARTUPINFO lpStartupInfo,
 *   __out        LPPROCESS_INFORMATION lpProcessInformation
 * );
 */
static int
CreateProcess_cmd( ClientData data, Tcl_Interp *interp,
             int objc, Tcl_Obj * CONST *objv )
{
    LPSECURITY_ATTRIBUTES pattr;
    LPSECURITY_ATTRIBUTES tattr;
    STARTUPINFO sinfo;
    PROCESS_INFORMATION *pinfo;

    if ( objc != 2 ) {
        Tcl_ResetResult( interp );
        Tcl_WrongNumArgs( interp, 1, objv, "CreateProcess" );
        return TCL_ERROR;
    }

    pinfo = HeapAlloc( heap, HEAP_ZERO_MEMORY, sizeof(LPPROCESS_INFORMATION) );
    if ( pinfo == NULL ) {
        Tcl_SetResult( interp, "failed to alloc pinfo", TCL_STATIC );
        return TCL_ERROR;
    }

    char *command = Tcl_GetStringFromObj( objv[1], NULL );

    int result = CreateProcess(
        NULL,    // no module
        command, // Command line
        NULL,    // Process handle not inheritable
        NULL,    // Thread handle not inheritable
        FALSE,   // Set handle inheritance to false
        0,       //No creation flags
        NULL,    // Use parent's env block
        NULL,    // Use parent's starting directory
        &sinfo, pinfo
    );

    char *name = "p";
    Tcl_CreateObjCommand( interp, name, Process_obj, (ClientData)pinfo, Process_delete );

    Tcl_SetResult( interp, name, TCL_VOLATILE );
    return TCL_OK;
}

/**
 */
int Process_Initialize( Tcl_Interp *interp ) {
    Tcl_Command command;

    Tcl_Namespace *ns = Tcl_CreateNamespace(interp, "Process", (ClientData)0, NULL);
    if ( ns == NULL ) {
        return TCL_ERROR;
    }

    if ( Tcl_LinkVar(interp, "Process::debug", (char *)&debug, TCL_LINK_INT) != TCL_OK ) {
        printf( "failed to link Process::debug" );
        exit( 1 );
    }

    heap = GetProcessHeap();
    if ( heap == NULL ) {
        printf( "Failed to get the default process heap handle: '%s'\n", GetLastError() );
        return TCL_ERROR;
    }

    command = Tcl_CreateObjCommand(interp, "CreateProcess", CreateProcess_cmd, (ClientData)0, NULL);
    if ( command == NULL ) {
        return TCL_ERROR;
    }

    return TCL_OK;
}

/*
 * vim:autoindent
 * vim:expandtab
 */
