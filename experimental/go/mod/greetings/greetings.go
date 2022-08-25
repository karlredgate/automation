
package greetings
import "fmt"

func Hello( name string ) string {
    message := fmt.Sprintf( "hello %s, welcome", name )
    return message
}
