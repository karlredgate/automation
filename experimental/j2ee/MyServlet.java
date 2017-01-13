
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class MyServlet extends HttpServlet {
	public void doGet( HttpServletRequest request,
			   HttpServletResponse response )
		throws ServletException, IOException
	{
		response.setContentType( "text/html" );
		PrintWriter body = response.getWriter();
		body.println( "<html><head><title>junk</title></head>" );
		body.println( "<body>crap</body></html>" );
	}

	public String getServletInfo() {
		return "Dumb servlet";
	}
}
