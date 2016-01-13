
default: test

test: basic
	echo '{"s":3}' | ./basic

basic: basic.o scanner.o errors.o
	cc -o $@ $^

clean:
	rm basic *.o
