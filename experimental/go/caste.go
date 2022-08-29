
package main

import "fmt"

func main() {
    var i interface{}
    i = "a string"
    s := i.(string)
    fmt.Println( "val",s )
    i = 2022
    i = 3.145
    // this syntax only works for an interface
    r := i.(float64)
    fmt.Println( "val",r )
    a := []byte( `hello` )
    fmt.Println( "a",a,"stringVal",string(a) )
}
