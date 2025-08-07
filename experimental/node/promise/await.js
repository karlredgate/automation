
async function myFunction() {
}

async function a() {
}

function b() {
}

const isAsync = myFunction.constructor.name === "AsyncFunction";

function check( f ) {
    return (f.constructor.name === "AsyncFunction") ? 'async' : 'sync';
}

console.log( "a is " + check(a) );
console.log( "b is " + check(b) );
