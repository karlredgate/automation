
package main

import (
    "os"
    "fmt"
    "runtime"
    "runtime/debug"
    "runtime/pprof"
)

func watcher( done chan bool ) {
    <-done
    fmt.Println( "exit" )
}

func main() {
    done := make( chan bool )
    go watcher( done )
    fmt.Println( "count", runtime.NumGoroutine() )
    go watcher( done )
    fmt.Println( "count", runtime.NumGoroutine() )
    go watcher( done )
    fmt.Println( "count", runtime.NumGoroutine() )
    debug.PrintStack()
    pprof.Lookup("goroutine").WriteTo(os.Stdout,1)
    done <- true
    done <- true
    done <- true
}
