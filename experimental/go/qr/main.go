// Russ Cox code for QR codes ...

package main

import "os"
// import "fmt"
import "rsc.io/qr"

func main() {
    code,err := qr.Encode("https://www.cnn.com",qr.M)
    if err != nil {
	panic( err )
    }
    os.WriteFile( "qr.png", code.PNG(), 0666 )
}
