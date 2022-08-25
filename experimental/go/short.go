
package main

import "fmt"

func foo() {
    if 3 == 3 { return }
    fmt.Println( "FAILED" )
}

/*
 * why is there a difference between ? "<-" and ":= <-" ??
 * the := does type detection
 */
func main() {
    fmt.Println( "starting..." )
    foo()
    fmt.Println( "... should not have seen a failure" )
}
