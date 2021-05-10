
/*
 client uses UI - requests a map
 UI sends API request to SS API
 SS API requests new map from MROM API
 MROM allocates a map or punts
 MROM writes to p4 (use as a queue?)
 */

mtype = { RESET };

typedef MCM_MapRequest {
    int map_id;
    int region[20];
};

typedef StagedConfig {
    int id;
};

chan MCM = [5] of { MCM_MapRequest };
chan P4  = [0] of { StagedConfig };

chan guard = [0] of { int };
proctype Watchdog() {
    printf( "watchdog starting\n" );
    do
    /* :: timeout -> printf( "timed out knr\n" ) */
    :: timeout -> guard ! RESET
    od
}

int clock = 0;
proctype Clock() {
    do
    :: clock++
       if
       :: ( (clock % 60) == 0 ) -> printf( "minute\n" )
       fi
    od
}

proctype Cron() {
    printf( "cron starting\n" );
    guard ! 4;
    printf( "cron started\n" );
    guard ! 5;
    do
    :: printf( "one\n" )
    :: printf( "two\n" )
    :: printf( "three\n" )
    od;
}

proctype PerforceStore() {
    skip;
}

proctype MROM_Request() {
    skip;
    /* get API request from SS API 
     * check if map available
     * allocate or punt
     * add regions
     * send to staging area
     */
    MCM_MapRequest foo;
    foo.map_id = 10;
    MCM ! foo
}

/*
 * MCM processes
 * an API that it accepts messages on - what messages?
 * loop on p4 to look for files to process?
 * loop like cron periodically run MCM bcp?
 */
proctype MCM_Process() {
    MCM_MapRequest m;
    printf( "Periodic MCM process\n" );
    MCM ? m;
    printf( "MCM receive message for id %d\n", m.map_id );
}

proctype MCM_InformPortal() { /* send message to portal channel */
    skip
}

/*
 * int: Map id
 * send: map name?, china bool, ??
 */
chan SS_API_Request = [0] of { int };

proctype SS_API() { /* make a request to API */
    int id;
    do
    :: SS_API_Request ? id
    od
    skip
}

proctype Browser() { /* make a request to API */
    SS_API_Request ! 99;
    skip
}

init {
    run Clock();
    run MROM_Request();
    run MCM_Process();
    run SS_API();
    run Browser();
    run Cron();
    /* run Watchdog(); */
    int foo;
    guard ? foo;
    printf( "recv %d\n", foo);
    printf( "clock is %d at end\n", clock );
}

/* vim: set autoindent expandtab sw=4 : */
