
package main

import (
    "fmt"
    // "os"
)

func main() {
    naturals := make( chan int )
    squares  := make( chan int )

    go func () {
	for x := 0; x < 20 ; x++ {
	    naturals <- x
	}
	// os.Exit(0)
	close( naturals )
    }()
    go func () {
	for {
	    x,ok := <- naturals
	    if ! ok { break }
	    squares <- x * x
	}
	close( squares )
    }()

    for x := range squares {
	fmt.Println( x )
    }
}
