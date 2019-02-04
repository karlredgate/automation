
public
class MatchTarget
implements Cloneable {
    String hostname;
    String path;

    MatchTarget( String _hostname, String _path ) {
        this.hostname = _hostname;
        this.path     = _path;
    }

    protected Object
    clone()
    throws CloneNotSupportedException
    {
        MatchTarget clone = (MatchTarget) super.clone();
        clone.hostname += "-copy";
        return clone;
    }

    public String
    toString() {
        return "Match(" + hostname + "," + path + ")";
    }

}

/* vim: set autoindent expandtab sw=4 : */
