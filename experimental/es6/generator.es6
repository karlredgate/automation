
// This works in Node - is it ES6

function* fib() {
    var a = 0;
    var b = 1;
    while (true) {
	yield a;
        var c = a + b;
	a = b;
	b = c;
    }
}

f = fib();
console.log( f.next().value );
console.log( f.next().value );
console.log( f.next().value );
console.log( f.next().value );
console.log( f.next().value );
console.log( f.next().value );
console.log( f.next().value );
console.log( f.next().value );
console.log( f.next().value );
console.log( f.next().value );
console.log( f.next().value );
console.log( f.next().value );
console.log( f.next().value );
