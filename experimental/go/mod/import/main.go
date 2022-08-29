
package main

import (
    "fmt"     // direct import
    _ "os"    // blank import
    os2 "os"  // aliased import
    . "github.com/diskfs/go-diskfs"  // "dot" import
                                     // AND "relative" import
)
/*
   Dot import is something that most users haven’t heard of. It is
   basically a rare type of import that is mostly used for testing
   purposes. Testers use this kind of import in order to test whether
   their public structures/functions/package elements are functioning
   properly. Dot import provides the perks of using elements of a package
   without mentioning the name of the package and can be used directly. As
   many perks as it provides, it also brings along with it a couple of
   drawbacks such as namespace collisions. Refer the example for syntax
   and example code for a better understanding of the dot import.
 */

func main() {
    fmt.Println("test imports")
}
