
import java.io.StringWriter;

import org.apache.velocity.Template;
import org.apache.velocity.VelocityContext;
import org.apache.velocity.app.Velocity;
import org.apache.velocity.exception.*;

public class ClubApp {

    public static void main( String[] args ) {

        try {
            Velocity.init();
        } catch( Exception x ) {
            System.err.println( "Failed to initialize Velocity: " + x );
            System.exit( 1 );
        }

        Template clubTemplate = null;
        try {
            clubTemplate = Velocity.getTemplate( "ClubApp.vm" );
        } catch( ResourceNotFoundException rnfX ) {
            System.err.println( "Template not found: " + rnfX );
            System.exit( 1 );
        } catch( ParseErrorException peX ) {
            System.err.println( "Failed to parse template: " + peX );
            System.exit( 1 );
        } catch( Exception x ) {
            System.err.println( "Failed to initialize template: " + x );
            System.exit( 1 );
        }

        VelocityContext context = new VelocityContext();

        context.put( "firstName", "John" );
        context.put( "lastName", "Doe" );
        context.put( "streetAddress", "123 Jane Ave." );
        context.put( "city", "Azusa" );
        context.put( "state", "CA" );
        context.put( "zip", "91702" );
        context.put( "phoneNumber", "626-555-1234" );
        context.put( "emailAddress", "john@nodom.com" );
        context.put( "occupation", "Web Developer" );
        context.put( "otherInterests", "Hiking,Biking" );
        context.put( "appType", "New" );
        context.put( "useTime", "6 months" );
        context.put( "useType", "Work" );
        context.put( "wantNewsletter", "Yes" );

        // Merge template and context
        StringWriter writer = new StringWriter();

        try {
            clubTemplate.merge( context, writer );
        } catch( ResourceNotFoundException rnfX ) {
            System.err.println( "Template not found on merge: " + rnfX );
            System.exit( 1 );
        } catch( ParseErrorException peX ) {
            System.err.println( "Failed to parse template on merge: " + peX );
            System.exit( 1 );
        } catch( MethodInvocationException miX ) {
            System.err.println( "Application method exception: " + miX );
            System.exit( 1 );
        } catch( Exception x ) {
            System.err.println( "Failed to merge template: " + x );
            System.exit( 1 );
        }

        // Render merged content
        System.out.println( writer.toString() );

    }

}

/* vim: set autoindent expandtab sw=4 : */
