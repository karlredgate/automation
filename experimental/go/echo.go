
package main

import ( "os"; "fmt" )

func main() {

    for _, arg := range os.Args {
	fmt.Println( arg )
    }

    fmt.Println( "skip arg 0" )
    for _, arg := range os.Args[1:] {
	fmt.Println( arg )
    }

    for i := 0; i < len(os.Args); i++ {
	fmt.Println( os.Args[i] )
    }

}
