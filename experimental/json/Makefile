
default: test

test: basic
	echo '{"s":3}' | ./basic
	: ================ RANDOM TEST 1
	dada json.pb | tee /dev/stderr | ./basic
	: ================ RANDOM TEST 2
	dada json.pb | tee /dev/stderr | ./basic

basic: basic.o scanner.o errors.o
	cc -o $@ $^

clean:
	rm basic *.o
