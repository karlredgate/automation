README
======

Use this as a reference for TomCat -- there may be better
references (JEE doc?).

<http://wiki.metawerx.net/wiki/Web.xml>

The Servlet 2.4 specification says this about `WEB-INF` (page 70):

> A special directory exists within the application hierarchy named
> `WEB-INF` This directory contains all things related to the application
> that aren’t in the document root of the application. The  `WEB-INF`
> node is not part of the public document tree of the application.
> No file contained in the `WEB-INF` directory may be served directly
> to a client by the container. However, the contents of the  `WEB-INF`
> directory are visible to servlet code using the getResource and
> getResourceAsStream method calls on the ServletContext, and may be
> exposed using the RequestDispatcher calls.

This means that `WEB-INF` resources are accessible to the resource
loader of your Web-Application and not directly visible for the
public.

This is why a lot of projects put their resources like JSP files,
JARs/libraries and their own class files or property files or any
other sensitive information in the `WEB-INF` folder. Otherwise they
would be accessible by using a simple static URL (usefull to load
CSS or Javascript for instance).

Your JSP files can be anywhere though from a technical perspective.
For instance in Spring you can configure them to be in `WEB-INF`
explicitly:

```
<bean
  id="viewResolver"
  class="org.springframework.web.servlet.view.InternalResourceViewResolver"
    p:prefix="/WEB-INF/jsp/" 
    p:suffix=".jsp" >
</bean>
```

The `WEB-INF/classes` and `WEB-INF/lib` folders mentioned in Wikipedia's
WAR files article are examples of folders required by the Servlet
specification at runtime.

It is important to make the difference between the structure of a
project and the structure of the resulting WAR file.

The structure of the project will in some cases partially reflect
the structure of the WAR file (for static resources such as JSP
files or HTML and JavaScript files, but this is not always the case.

The transition from the project structure into the resulting WAR
file is done by a build process.

While you are usually free to design your own build process, nowadays
most people will use a standardized approach such as Apache Maven.
Among other things Maven defines defaults for which resources in
the project structure map to what resources in the resulting artifact
(the resulting artifact is the WAR file in this case). In some cases
the mapping consists of a plain copy process in other cases the
mapping process includes a transformation, such as filtering or
compiling and others.

One example: The `WEB-INF/classes` folder will later contain all
compiled java classes and resources (src/main/java and src/main/resources)
that need to be loaded by the Classloader to start the application.

Another example: The `WEB-INF/lib` folder will later contain all jar
files needed by the application. In a maven project the dependencies
are managed for you and maven automatically copies the needed jar
files to the `WEB-INF/lib` folder for you. That explains why you don't
have a lib folder in a maven project.

When you deploy a Java EE web application (using frameworks or not),its structure must follow some requirements/specifications. These specifications come from : 

 * The servlet container (e.g Tomcat)
 * Java Servlet API
 * Your application domain

 1. The Servlet container requirements
    If you use Apache Tomcat, the root directory of your application
    must be placed in the webapp folder. That may be different if
    you use another servlet container or application server.

 2. Java Servlet API requirements
    Java Servlet API states that your root application directory
    must have the following structure :

```
ApplicationName
|
|--META-INF
|--WEB-INF
      |_web.xml       <-- Here is the configuration file of your web app(where you define servlets, filters, listeners...)
      |_classes       <--Here goes all the classes of your webapp, following the package structure you defined. Only 
      |_lib           <--Here goes all the libraries (jars) your application need
```

These requirements are defined by Java Servlet API.

<!-- vim: set autoindent expandtab sw=4 syntax=markdown: -->
