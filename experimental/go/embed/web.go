
package main

import(
    "embed"
    "fmt"
    "net/http"
    "io/fs"
)

//go:embed root
var storage embed.FS

func main() {
    content,err := fs.Sub( storage,"root" )
    if ( err != nil ) {
	panic("failed to read file")
	fmt.Println("failed to read file")
    }
    http.Handle( "/", http.FileServer( http.FS(content) ) )
    http.ListenAndServe( ":8888", nil )
}
