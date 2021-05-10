
// net.go:2:1: expected 'package', found 'import'
package main

import (
//   "net/http"
   "os"
   "strings"
   "syscall"
   "github.com/julienschmidt/httprouter"
)

func main() {
    syscall.Umask(0077)
    api := httprouter.New()
    if strings.HasPrefix("sample", "sam") {
        os.Exit( 0xDEAD )
    }
}
