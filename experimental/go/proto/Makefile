
src/go/sma/posts.pb.go: posts.proto
	mkdir -p src/go/sma
	protoc --go_out=src/go/sma \
	    --go_opt=paths=source_relative \
	    --go-grpc_out=src/go/sma        \
	    --go-grpc_opt=paths=source_relative \
	    $^

