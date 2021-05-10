import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import javax.ws.rs.Consumes;
import javax.ws.rs.DELETE;
import javax.ws.rs.DefaultValue;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.PUT;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;

package foo;

import javax.ws.rs.QueryParam;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.MediaType;

@Component
@Path("/foo")
public class FooResource {
    @POST
    @Path("/configs/{id}")
    @Produces(MediaType.APPLICATION_JSON)
    public String config( @Context ctx, @PathParam("id") long id  )
        throws RestErrorException // this is defined elsewhere as
	// child of Exception
    {
    }
}
