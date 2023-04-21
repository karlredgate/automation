
package main

import (
    "os"
    "fmt"
    "encoding/json"
)

//  fmt.Println( "type",data.(type) )
// ./main.go:14:25: invalid AST: use of .(type) outside type switch

//  err := json.Unmarshal( os.Args[1], &i )
// ./main.go:15:28: cannot use os.Args[1] (variable of type string)
//                  as type []byte in argument to json.Unmarshal

func main() {
    if len(os.Args) < 2 {
        fmt.Println( "without a JSON string arg - you should see a panic" )
    }
    fmt.Println( "JSON", os.Args[1] )

    // obj := {}
    var i interface{}
    data := []byte( os.Args[1] )
    // fmt.Println( "type",data.(type) )
    // err := json.Unmarshal( []byte(os.Args[1]), &i )
    err := json.Unmarshal( data, &i )
    if err != nil {
	panic(err)
    }
    fmt.Println( "ARGS:", i )

    // if ("name" in i) {
    //if (i.name != nil) {
        //fmt.Println( "name:", i.name )
    //}
}
