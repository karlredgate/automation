
const wa = require( 'webassembly' );

function pri( module ) {
    console.log( "s= " + module.exports.mesg() );
}

function use( module ) {
    console.log( "1+2= " + module.exports.add(1,2) );
}

const hello = wa.load( 'hello.wasm' );
hello.then( use );
hello.then( pri );

