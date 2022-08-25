
package main

import (
    "os"
    "fmt"
    "github.com/go-git/go-git/v5"
)

func main() {
    options := git.CloneOptions{ URL:"https://github.com/karlredgate/redx", Progress:os.Stdout }
    _,err := git.PlainClone( "redx", false, &options )
    if err != nil {
	fmt.Println("failed", err)
    }
}
