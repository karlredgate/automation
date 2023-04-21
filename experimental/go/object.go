
package main

import "fmt"

type Object struct {
    name string
}

// with anonymous fields - that can be only one of each type
type FieldObj struct {
    string
}

func main() {
    fmt.Println( "starting..." )

    // this is called an "anonymous structure"
    obj := struct { name string }{ name: "drexl" }
    fmt.Println( "plain object is ", obj )

    foo_s := FieldObj{"deadbeef"}
    fmt.Println( "anon field is", foo_s.string )

    this := Object{}
    this.name = "JUNK"
    // this.other = "JUNK"
    fmt.Println( "object is ", this )
}
