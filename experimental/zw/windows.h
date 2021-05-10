
#include <stdio.h>

#define NTSYSAPI
#define NTAPI
#define OPTIONAL

#define IN
#define OUT

#define FILE_ANY_ACCESS  0x0000;
#define FILE_READ_ACCESS 0x0001;

struct ZW_Object_Attributes {
    unsigned long flags;
};

struct ZW_IO_Status_Block {
    unsigned long flags;
};

typedef int NTSTATUS;

typedef unsigned int   DWORD;
typedef unsigned short WORD;
typedef unsigned long  ULONG;
typedef          void *PVOID;
typedef unsigned long long * PLARGE_INTEGER;
typedef FILE * PHANDLE;
typedef unsigned long ACCESS_MASK;
typedef struct ZW_Object_Attributes *POBJECT_ATTRIBUTES;
typedef struct ZW_IO_Status_Block *PIO_STATUS_BLOCK;


NTSYSAPI
NTSTATUS
NTAPI
ZwCreateFile( 
	OUT PHANDLE FileHandle,
	IN ACCESS_MASK DesiredAccess,
	IN POBJECT_ATTRIBUTES ObjectAttributes,
	OUT PIO_STATUS_BLOCK IoStatusBlock,
	IN PLARGE_INTEGER AllocationSize OPTIONAL,
	IN ULONG FileAttributes,
	IN ULONG ShareAccess,
	IN ULONG CreateDisposition,
	IN ULONG CreateOptions,
	IN PVOID EaBuffer OPTIONAL,
	IN ULONG EaLength
);
