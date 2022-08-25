package main

import (
    "fmt"; // "os"
    // Look for this package name starting from the parent dir that
    // contains a go.mod file
    "os-builder/cmd"
)

func main() {
    fmt.Println( "STARTING" )
    cmd.Execute()
}
