
package main

import (
    "fmt"
    "github.com/r3labs/sse/v2"
)

/*
func main() {
	events := make(chan *sse.Event)

	client := sse.NewClient("http://server/events")
	client.SubscribeChan("messages", events)
}


func main() {
	client := sse.NewClient("http://server/events")
	client.Connection.Transport =  &http.Transport{
		TLSClientConfig: &tls.Config{InsecureSkipVerify: true},
	}
}
*/

func main() {
    client := sse.NewClient("http://desktop-spotdisplay01:65033/events?ids=B05,B10,B12,C86")

	client.SubscribeRaw(func(msg *sse.Event) {
		// Got some data!
		fmt.Println(string(msg.Data))
	})
}

