
chan guard = [0] of { int };

int clock = 0;
proctype Clock() {
    do
    :: clock++
       if
       :: ( (clock % 60) == 0 ) -> printf( " ALARM: minute\n" )
       fi
    od;
    printf( "Clock done\n" );
}


proctype Cron() {
    printf( "cron starting\n" );
    guard ! 4;
    printf( "cron started\n" );
    do
    :: printf( "one\n" )
    :: printf( "one\n" )
    :: printf( "two\n" )
    :: printf( "two\n" )
    :: printf( "three\n" )
    :: printf( "three\n" )
    :: break
    od;
    printf( "Cron done\n" );
}

init {
    run Clock();
    run Cron();
    printf( "clock is %d at end\n", clock );
    int foo;
    guard ? foo;
    printf( "end\n" );
    do
    :: timeout -> printf( "timer tick\n" )
    od;
    skip
}

/* vim: set autoindent expandtab sw=4 : */
