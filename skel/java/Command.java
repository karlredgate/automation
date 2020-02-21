
public class Command {

    public static void
    main( String args[] ) {
        // for each arg?
        String arg = args[0];
        System.out.println( "parse the command line " + arg );
        String segments[] = arg.split("/");
        for ( String segment : segments ) {
            System.out.println( "Segment: " + segment );
        }
    }

}

/* vim: set autoindent expandtab sw=4 : */
