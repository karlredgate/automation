
const FS = require('fs');

const memory = new WebAssembly.Memory( {initial:2} );
const imports = {
    env: {
        memory: memory,
	_abort: function () {},
	_grow: function () {}
    }
};

const contents = FS.readFileSync( 'hello.wasm' );
const binary = new Uint8Array( contents.buffer )
// const mod = new WebAssembly.Module( binary );
// const Hello = WebAssembly.Instance( mod, imports );

function handle_error1(instance) {
    console.log( "ERROR1 - " + instance );
}

function handle_error2(instance) {
    console.log( "ERROR2 - " + instance );
}

function create_instance( m ) {
    console.log( "called create_instance with " + m );
    var i;
    try {
        i = WebAssembly.Instance(m,imports);
    } catch (e) {
	console.log( "Caught " + e );
    }
    console.log( "i == " + i );
    return i;
}

const Hello = WebAssembly.compile( binary ).then( create_instance, handle_error1 );
console.log( "Hello " + Hello );

console.log( "instance ??" );
function handle_instance(instance) {
    console.log( "instance = " + instance );
    console.log( "instance.exports.use = " + instance.exports.use );
    console.log( "instance = " + instance.exports.use() );
}
Hello.then( handle_instance, handle_error2 ).then( m => console.log("after " + m), handle_error2 );;

console.log( "instance ?? done" );

const buffer = new Uint8Array( memory.buffer );

const wa = require( 'webassembly' );

function pri( module ) {
    console.log( "s= " + module.exports.mesg() );
}

function use( module ) {
    console.log( "1+2= " + module.exports.add(1,2) );
}

// console.log( "HelloI " + HelloI.use() );
// Hello.exports.use();
// var A = new Hello();
// A.then( use );
// A.then( pri );

// const hello = wa.load( 'hello.wasm' );
// hello.then( use );
// hello.then( pri );

/*
 (node:5202) UnhandledPromiseRejectionWarning: TypeError: Cannot read property 'use' of undefined
 at handle_error (/Users/kredgate/wasm/hello.js:28:59)
 at <anonymous>
 at process._tickCallback (internal/process/next_tick.js:160:7)
 at Function.Module.runMain (module.js:703:11)
 at startup (bootstrap_node.js:193:16)
 at bootstrap_node.js:617:3
 (node:5202) UnhandledPromiseRejectionWarning: Unhandled promise rejection.
             This error originated either by throwing inside of an async
	     function without a catch block, or by rejecting a promise which
	     was not handled with .catch(). (rejection id: 1)
 (node:5202) [DEP0018] DeprecationWarning: Unhandled promise rejections are
             deprecated. In the future, promise rejections that are not handled
	     will terminate the Node.js process with a non-zero exit code.
 */
