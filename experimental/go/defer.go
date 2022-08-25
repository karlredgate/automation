
package main

import (
        "fmt"
)

func hook() {
    fmt.Println( "hook" )
}

func main() {
    defer hook()
    fmt.Println( "main" )
}
