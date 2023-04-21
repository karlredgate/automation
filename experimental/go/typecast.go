
package main

import "fmt"

type BB struct {
    s string
}

func inspectType( i interface{} ) {
    switch i.(type) {
    case int: fmt.Println("type is int")
    case string: fmt.Println("type is string")
    default: fmt.Println("type is UNKNOWN")
    }
}

type anything = interface{}

// "any" is an alias for interface{}
func main() {
    var i interface{}
    i = "a string"
    s := i.(string)
    inspectType( i )
    fmt.Println( "val",s )
    i = 2022
    inspectType( i )
    i = 3.145
    inspectType( i )
    // this syntax only works for an interface
    //   and is called a "type assertion" - does this interface contain this type?
    r := i.(float64)
    fmt.Println( "val",r )

    var i2 interface{} = BB{"some string"}
    fmt.Println( "i2",i2 )
    fmt.Println( "i2",i2.(BB) )
    a := []byte( `hello` )
    // this is a typecast
    fmt.Println( "a",a,"stringVal",string(a) )
}
