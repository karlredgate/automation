
package main

// if the greetings line is not present - then go mod tidy does nothing
// and "{"/"}" are not the separators for import - but it does not error
// and tidy does nothing if the error exists

import (
    "fmt"
    "redgates.com/greetings"
)

func main() {
    message := greetings.Hello("Robin")
    fmt.Println( message )
}
