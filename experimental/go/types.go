
package main

import ("fmt")

type NewName chan string

func consumer( p NewName ) {
    value := <- p
    // println inserts a space between values
    fmt.Println( "value is", value )
    fmt.Printf( "value is %s\n", value )
}

// add example of reflection to read this?
type Junk struct {
    s string `pkg:"value,anotherval" pkg2:"junk"`
    t string "unstructured tag info"
}

func main() {
    p := make (NewName)
    go consumer( p )
    p <- "deadbeef"
// cannot consume where produced - it is a deadlock
    // value := <- p
    // fmt.Println( "value is ", value )
    unprocessedString := `this can>: contain{} metachars`
    fmt.Println( "lit string:",unprocessedString )
}
