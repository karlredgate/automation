
CXXFLAGS+= -std=c++11
INCLUDES=-I/opt/local/include -I.

test: plugin-dump
	./plugin-dump < junk.out

plugin-dump: main.o plugin.pb.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -L/opt/local/lib -lprotobuf

main.o: main.cc plugin.pb.h
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c main.cc

plugin.pb.o: plugin.pb.cc
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $^

plugin.pb.h plugin.pb.cc: plugin.proto
	protoc --cpp_out=. $^

clean:
	rm -f *.o
	rm -f plugin-dump plugin.pb.h plugin.pb.cc


