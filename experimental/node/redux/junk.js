
function Foo() {
}

( function () {
	// create lots of junk in the enclosed env
	function Crap() {
	}
  } )(); // then call it to return the single obj - but do not polute global env

for ( var p in global ) {
    console.log( "PPP: " + p );
}
console.log( "G: " + Foo );
console.log( "G: " + Crap );
