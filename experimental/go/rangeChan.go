
package main

import ( "fmt" )

const (
    forall       = string(0x2200)
    exists       = string(0x2203)
    notexists    = string(0x2204)
    null         = string(0x2205)
    elementof    = string(0x2208)
    notelementof = string(0x2209)
    therefore    = string(0x2234)
    because      = string(0x2235)
)

func producer( channel chan string ) {
    channel <- "deadbeef"
    channel <- "feedface"
    channel <- "cafebabe"
    channel <- "d00dcafe"
    channel <- string(65)
    channel <- string(0x2200)
    channel <- forall + exists
    channel <- string(0x6566)
    close( channel ) // if no close - then deadlock in the `range` command
}

func main() {
    channel := make (chan string)
    go producer(channel)
    for value := range channel {
	fmt.Println( "value", value )
    }
}
