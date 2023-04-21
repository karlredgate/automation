
package main

import (
    "fmt"
    "context"
    "net"

    "google.golang.org/grpc"
    pb "github.com/karlredgate/echo/proto"
)

const (
    port = ":50051"
)

type server struct {
    pb.UnimplementedGreeterServer
}

func (s *server) SayHello(ctx context.Context, in *pb.EchoRequest) (*pb.EchoReply, error) {
    fmt.Printf( "server-recv: %v\n", in.GetName() )
    return &pb.EchoReply{Mesg:"RESP:"+in.GetName()}, nil
}

func main() {
    fmt.Println("grpc")
    listener,err := net.Listen( "tcp", port )
    if err != nil {panic(err)}
    serv := grpc.NewServer()
    pb.RegisterGreeterServer( serv, &server{} )
    err = serv.Serve(listener)
    if err != nil {panic(err)}
}
