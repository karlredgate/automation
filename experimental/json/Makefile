
default: test

test: basic
	echo '{"s":3}' | ./basic
	echo '{"first":3,"2nd":"stuff","abc":{"a":1,"b":2,"c":3}}' | ./basic
	echo '[1,2,3]' | ./basic
	: ================ RANDOM TEST 1
	dada json.pb | tee /dev/tty | ./basic
	: ================ PASSED
	: ================ RANDOM TEST 2
	dada json.pb | tee /dev/tty | ./basic
	: ================ PASSED

basic: basic.o scanner.o errors.o
	cc -o $@ $^

clean:
	rm basic *.o
