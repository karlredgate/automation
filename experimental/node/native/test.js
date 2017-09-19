// hello.js
const hello = require('./build/Release/hello');

console.log( hello.hello() );

function f( mesg ) {
    console.log( "Callback says: " + mesg );
}

hello.cb( f );

var o = hello.create( "JunkMsg" );
console.log( o.msg );

var obj = new hello.Thing( 3 );
console.log( obj.plusOne() );
console.log( obj.plusOne() );
console.log( obj.plusOne() );

var obj2 = new hello.Thing( 9 );
console.log( hello.add_thing( obj, obj2 ) );

// Prints: 'world'
// vim:autoindent expandtab sw=4
