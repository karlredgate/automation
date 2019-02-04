
public class Test {
    public static void
    main( String args[] ) {
        SecurityConfig config1 =
            new SecurityConfig( "junk", "example.com", "/" );
        System.out.println( "created a config " + config1 );
        try {
            SecurityConfig config2 = (SecurityConfig) config1.clone();
            System.out.println( "cloned a config " + config2 );
        } catch ( CloneNotSupportedException error ) {
            System.out.println( "Failed to clone" );
        }
    }
}

/* vim: set autoindent expandtab sw=4 : */
