package main

import "fmt"
import "reflect"

func main() {
    var map_of_string_to_array_of_string map[string][]string
    map_of_string_to_array_of_string = make( map[string][]string )
    fmt.Println( "type:", reflect.TypeOf( map_of_string_to_array_of_string ) )
 // ./map.go:10:47: cannot use [...]string{…} (value of type [4]string) as type []string in assignment
 // map_of_string_to_array_of_string["foo"] = [...]string{ "dead", "beef", "feed", "face" }
    map_of_string_to_array_of_string["foo"] = []string{ "dead", "beef", "feed", "face" }
    fmt.Println( "val:", map_of_string_to_array_of_string["foo"][1] ) // val: beef
}
