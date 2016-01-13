
default: test

test: basic
	echo '{"s":3}' | ./basic

basic: basic.o
	cc -o $@ $^
