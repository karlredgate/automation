
package main

import( "embed";"fmt" )

//go:embed notes.txt
var Files embed.FS

//go:embed root
var storage embed.FS

func main() {
    data,err := Files.ReadFile("notes.txt")
    if ( err != nil ) {
	fmt.Println("failed to read file")
    }
    fmt.Println( string(data) )

    fmt.Println("RESOLVE")
    data,_ = storage.ReadFile( "root/etc/resolv.conf" )
    fmt.Println( string(data) )

    fmt.Println( "done" )
}
