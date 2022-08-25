
package main

import "fmt"

type Object struct {
    name string
}

func main() {
    fmt.Println( "starting..." )
    this := Object{}
    this.name = "JUNK"
    // this.other = "JUNK"
    fmt.Println( "object is ", this )
}
