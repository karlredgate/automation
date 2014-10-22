
/*
 * Run and it will report default stack size.
 *
 * Run as '$ STACK_KB=512 ./stack' to test with 512K stack.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define NTHREADS 100
#define KB(n) ((n)/1024)

struct thread_info {
    pthread_t tid;
};

void *
dowork( void *arg ) {
    sleep( 2 );
}

unsigned long
memory_report() {
    int pagesize = getpagesize();

    unsigned long size; 
    unsigned long resident; 
    unsigned long share; 
    unsigned long text; 
    unsigned long lib; 
    unsigned long data; 
    unsigned long dt;

    FILE *f = fopen( "/proc/self/statm", "r" );
    if ( f == NULL ) {
	perror( "fopen" );
	exit( -1 );
    }

    fscanf( f, "%lu %lu %lu %lu %lu %lu %ld", 
               &size, &resident, &share, &text, &lib, &data, &dt );
    fclose( f );

    printf( "Memory size is %lu KB\n", KB(size * pagesize) );

    return size * pagesize;
}

size_t
set_stack_size( pthread_attr_t *attr ) {
    size_t stacksize;

    pthread_attr_init( attr );
    pthread_attr_getstacksize( attr, &stacksize );
    printf( "Default stack size = %d KB\n", KB(stacksize) );

    char *stack_kb = getenv("STACK_KB");

    if ( stack_kb == NULL ) return;

    printf( "Stack env '%s'\n", stack_kb );
    sscanf( stack_kb, "%lu", &stacksize );

    stacksize *= 1024;
    printf( "Setting stack size = %d KB\n", KB(stacksize) );
    pthread_attr_setstacksize( attr, stacksize );

    return stacksize;
}

int main( int argc, char **argv ) {
    pthread_attr_t attr;
    size_t stacksize;
    struct thread_info threads[NTHREADS];
    int thread_num;

    unsigned long start = memory_report();

    
    printf( "Create %d threads with stack size = %d\n",
            NTHREADS, KB(set_stack_size(&attr)) );

    for ( thread_num = 0 ; thread_num < NTHREADS ; thread_num++ ) {
	struct thread_info *current = &( threads[thread_num] );
        if ( pthread_create(&(current->tid), &attr, dowork, current) != 0 ) {
            perror( "pthread_create" );
            exit( -1 );
        }
        pthread_yield(); /* to make sure thread gets started */
    }

    unsigned long end = memory_report();
    unsigned long delta = end - start;

    printf( "Memory delta is %lu KB (%lu MB)\n", KB(delta), KB(KB(delta)) );

    pthread_exit(NULL);
}

/* vim: set autoindent expandtab sw=4: */
