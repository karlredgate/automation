
package main

import ( "fmt" )

type Weekday int

// is this really a generator?
const (
    Sunday Weekday = iota
    Monday; Tuesday; Wednesday; Thursday; Friday; Saturday
)

const (
    First int = iota
    Second = iota
    Third = iota
    Fourth; Fifth; Sixth; Seventh
)

func main() {
    fmt.Println( "const Monday is ",  Monday )
    fmt.Println( "const Sunday is ",  Sunday )
    // ./generator.go:16:30: cannot use iota outside constant declaration
    // fmt.Println( "iota is ", iota )
    // fmt.Println( "iota is ", iota )
    fmt.Println( "const First is ",  First )
    fmt.Println( "const Second is ",  Second )
    fmt.Println( "const Third is ",  Third )
}
