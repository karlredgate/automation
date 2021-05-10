
test: closure
	./closure

closure: closure.cpp
	$(CXX) -std=c++11 -stdlib=libc++ -o $@ $<
	: g++ -std=c++11 -o $@ $<


clean:
	rm closure
