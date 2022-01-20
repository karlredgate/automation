
// rest and spread syntax with ...
// these examples are "spread"

var a = [ {id:1}, {id:2}, {id:3} ];

var b = a;  // copy the ref - same array
   // modify b modifies a

var c = [...a]; // shallow copy of array
   // modify c does not modify a
   // however - modify the objects within c - 
   //    is visible in a objects - same refs

