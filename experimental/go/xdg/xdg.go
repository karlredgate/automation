package main

import ( "fmt"; "path/filepath"; "github.com/adrg/xdg" )

func main() {
    path := filepath.Join("osb","resources","filename1")
    fmt.Println( "path:", path )
    cache, err := xdg.CacheFile(path)
    if err != nil {
	fmt.Println( "Err: ", err )
    }
    fmt.Println( "xdg:", cache )
    return
}
