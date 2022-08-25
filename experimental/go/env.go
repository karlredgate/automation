
package main

import ( "os"; "fmt")

func main() {
    for _, env := range os.Environ() {
	fmt.Println( env )
    }
}
