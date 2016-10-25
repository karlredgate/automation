
// private vars are created using closures

function Box( size ) {
    this.size = size;
    var _volume = size * size;
    this.volume = function () { return _volume; }
}

var x = new Box( 3 );
console.log( "X: " + x );
console.log( "x.volume = " + x.volume() );
console.log( "x._volume = " + x._volume );
