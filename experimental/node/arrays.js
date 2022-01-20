
var words = [ 'apple', 'acre', 'babble', 'cacophony', 'deadwood', 'excrement',
              'finesse', 'guerrilla', 'heliotrope', 'icepick', 'jackalope',
              'khaki', 'lopsided', 'mechanical', 'norn' ];

var early = words.filter( word => word < "me" );
console.log( early );

// words.filter( (element, index, array) => { ... }, thisArg )

if ( process.version > "v15" ) {
    console.log( words.at(-1) ); // last element
} else {
    console.log( "skip 'at()' test - does not work on version " + process.version );
}

var more = words.concat( ['operator','procrustes'] );

var iter = more.entries();
console.log( iter.next().value );
console.log( iter.next().value );

if ( words.every( element => element < "one" ) ) {
    console.log( "all words are lex less than the string 'one'" );
}

// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/every
// look at the rest of these methods...

var upper = more.map( word => word.toUpperCase() );
console.log( upper );

var n = [1,2,3];
var four = n.push(4); // return value is the value pushed, not the array
console.log( n );
var o = n.pop();

// reduce is called inject in FP
var sum = n.reduce( (prev,curr) => prev + curr );
console.log( "sum of n is " + sum );

var array_w_7_slots = Array(7);
var array_w_1_slot_val_7 = Array.of(7);
