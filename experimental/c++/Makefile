
test: closure foreach
	./closure
	./foreach

closure: closure.cpp
	$(CXX) -std=c++11 -stdlib=libc++ -o $@ $<
	: g++ -std=c++11 -o $@ $<

foreach: foreach.cc
	$(CXX) -std=c++11 -stdlib=libc++ -o $@ $<

clean:
	rm closure
