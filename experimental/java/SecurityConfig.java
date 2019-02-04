
public
class SecurityConfig
implements Cloneable {
    String name;
    MatchTarget match;

    SecurityConfig( String _name, String _host, String _p ) {
        this.name = _name;
        match = new MatchTarget( _host, _p );
    }

    protected Object
    clone()
    throws CloneNotSupportedException
    {
        SecurityConfig clone = (SecurityConfig) super.clone();
        clone.match = (MatchTarget) this.match.clone();
        return clone;
    }

    SecurityConfig
    getClone() {
        try {
            return (SecurityConfig) super.clone();
        } catch ( CloneNotSupportedException error ) {
            return this;
        }
    }

    public String
    toString() {
        return "<SecurityConfig: " + name + " -> " + match + ">";
    }

}

/* vim: set autoindent expandtab sw=4 : */
