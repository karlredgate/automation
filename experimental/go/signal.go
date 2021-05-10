
package main

import "fmt"

var c = make( chan int )

func service() {
    c <- 0x6566
}

/*
 * why is there a difference between ? "<-" and ":= <-" ??
 */
func main() {
    // var result = 0
    go service()
// ./signal.go:15: invalid operation: result <- c (send to non-chan type int)
//  result <- c
    result := <- c
    fmt.Println( "received ", string(result) )
}
