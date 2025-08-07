
import std.stdio: writefln;

void main( string[] args ) {
    foreach (i, arg; args)
	writefln( "args[%d] = '%s'", i, arg );
}
