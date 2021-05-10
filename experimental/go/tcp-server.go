package main

import "net"
import "fmt"
import "bufio"
import "strings" // only needed below for sample processing

func main() {
  fmt.Println("Launching server...")

  listener, _ := net.Listen("tcp", ":8081") // listen on all interfaces
  sock, _ := listener.Accept()              // accept connection on port

  for {
    // will listen for message to process ending in newline (\n)
    message, _ := bufio.NewReader(sock).ReadString('\n')
    fmt.Print("Message Received:", string(message))
    // sample process for string received
    newmessage := strings.ToUpper(message)
    // send new string back to client
    sock.Write( []byte(newmessage + "\n") )
  }
}
