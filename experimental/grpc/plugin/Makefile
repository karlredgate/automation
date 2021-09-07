
CXXFLAGS+= -std=c++11
INCLUDES=-I/opt/local/include -I.

test: plugin-dump
	./plugin-dump < junk.out
	./plugin-dump < file.protobuf  >f.p

# plugin-dump: main.o plugin.pb.o google/protobuf/descriptor.pb.o
plugin-dump: main.o plugin.pb.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -L/opt/local/lib -lprotobuf

main.o: main.cc plugin.pb.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c main.cc

plugin.pb.o: plugin.pb.cc
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $^

plugin.pb.h plugin.pb.cc: plugin.proto
	protoc --cpp_out=. $^

google/protobuf/descriptor.pb.o: google/protobuf/descriptor.pb.cc
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $^ -o $@

google/protobuf/descriptor.pb.h google/protobuf/descriptor.pb.cc: google/protobuf/descriptor.proto
	protoc --cpp_out=. $^

hack:
	protoc --cpp_out=. --grpc_out=. --plugin=protoc-gen-grpc="$(PWD)/ggg" plugin.proto

clean:
	rm -f *.o
	rm -f plugin-dump plugin.pb.h plugin.pb.cc


