import std.stdio : writeln;
import std.range : iota;
import std.parallelism : parallel;

void main() {
    foreach ( i ; iota(11).parallel ) {
	writeln( "processing ", i );
    }
}
