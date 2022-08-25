
package main

import ("fmt")

type NewName chan string

func consumer( p NewName ) {
    value := <- p
    // println inserts a space between values
    fmt.Println( "value is", value )
    fmt.Printf( "value is %s\n", value )
}

func main() {
    p := make (NewName)
    go consumer( p )
    p <- "deadbeef"
// cannot consume where produced - it is a deadlock
    // value := <- p
    // fmt.Println( "value is ", value )
}
