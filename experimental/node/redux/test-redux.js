
var Redux = require('redux');

function red( state, action ) {
    return state;
}

var store = Redux.createStore( red );
console.log( store.getState() );

function sub() {
}

store.subscribe( sub );

// vim:autoindent expandtab sw=4
