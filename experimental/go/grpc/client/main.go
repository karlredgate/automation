
package main

import (
    "fmt"
    "context"
    "os"
    "time"

    "google.golang.org/grpc"
    pb "github.com/karlredgate/echo/proto"
)

const (
    address = "localhost:50051"
    defaultName = "world"
)

func main() {
    fmt.Println("client-grpc")
    conn,err := grpc.Dial( address, grpc.WithInsecure(), grpc.WithBlock() )
    if err != nil {panic(err)}
    defer conn.Close()

    client := pb.NewGreeterClient(conn)

    name := defaultName
    if len(os.Args) > 1 {
	name = os.Args[1]
    }
    ctx,cancel := context.WithTimeout( context.Background(), time.Second )
    defer cancel()

    resp,err := client.SayHello( ctx, &pb.EchoRequest{Name:name} )
    if err != nil {panic(err)}

    fmt.Printf( "client-Greet: %s\n", resp.GetMesg() )
}
