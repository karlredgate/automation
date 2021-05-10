
package main
import "fmt"

/*
Good stuff to read in this link
https://golang.org/doc/effective_go.html#blank
We've mentioned the blank identifier a couple of times now, in the
context of for range loops and maps. The blank identifier can be
assigned or declared with any value of any type, with the value
discarded harmlessly. It's a bit like writing to the Unix /dev/null
file: it represents a write-only value to be used as a place-holder
where a variable is needed but the actual value is irrelevant. It
has uses beyond those we've seen already.

was reading here...
https://www.tutorialspoint.com/go/go_variables.htm
continue this
*/

func main() {
    var age int; _ = age;
    var a uint8; _ = a;
    var b uint64; _ = b;
    var c int64; _ = c;
    var fa float32; _ = fa;
    var fb complex128; _ = fb;
    var d byte; _ = d; // uint8
    var e rune; _ = e; // int32
    var f uint; _ = f; // 32 or 64
    var p uintptr; _ = p;
    inferMe := 32; _ = inferMe;

    fmt.Println( "hello" )
}
