
package main

import (
    "fmt"
    "unsafe"
    "math"
)

func print(a uint64) {
    fmt.Println("print",a)
}

func main() {
    f1 := func(s string) {}
    f2 := func(i int) int { return i + 1 }
    pointers := []unsafe.Pointer{
        unsafe.Pointer(&f1),
        unsafe.Pointer(&f2),
    }
    f3 := (*func(int) bool)(pointers[1]) // note, not int
    fmt.Println((*f3)(1))

    fn := print
    faked := *(*func(float64))(unsafe.Pointer(&fn))
    fmt.Println("faked")
    faked(1.0)

    // For comparison
    num := math.Float64bits(1.0)
    fmt.Println("float64")
    print(num)
}
