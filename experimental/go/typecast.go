
package main

import "fmt"

type BB struct {
    s string
}

func main() {
    var i interface{}
    i = "a string"
    s := i.(string)
    fmt.Println( "val",s )
    i = 2022
    i = 3.145
    // this syntax only works for an interface
    //   and is called a "type assertion" - does this interface contain this type?
    r := i.(float64)
    fmt.Println( "val",r )

    var i2 interface{} = BB{"some string"}
    fmt.Println( "i2",i2.(BB) )
    a := []byte( `hello` )
    // this is a typecast
    fmt.Println( "a",a,"stringVal",string(a) )
}
