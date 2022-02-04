
// https://mockend.com/
// https://jsonplaceholder.typicode.com/

const https = require( 'https' );
var url = 'https://www.google.com/';

function json_handler( response ) {
    console.log( "code " + response.statusCode );
    if ( response.statusCode !== 200 ) {
	console.error( "NOT ok from server" );
        response.resume();
        return;
    }

    let data = '';
    response.on( 'data', chunk => data += chunk );
    response.on( 'close', () => console.log(JSON.parse(data)) );
}

function post_handler( response ) {
    console.log( "code " + response.statusCode );
    if ( response.statusCode !== 201 ) {
	console.error( "NOT ok from server" );
        response.resume();
        return;
    }

    let data = '';
    response.on( 'data', chunk => data += chunk );
    response.on( 'close', () => console.log(JSON.parse(data)) );
}

function handler( response ) {
    console.log( "code " + response.statusCode );
    if ( response.statusCode !== 200 ) {
	console.error( "NOT ok from server" );
        response.resume();
        return;
    }

    let data = '';
    response.on( 'data', chunk => data += chunk );
    response.on( 'close', () => console.log("recv " + data.length) );
}

let request = https.get( url, handler );

function err_handler( err ) {
    console.error(`Encountered an error trying to make a request: ${err.message}`);
}
request.on( 'error', err_handler );


let options = {
    method:'GET'
};

url = 'https://jsonplaceholder.typicode.com/users?_limit=2';
request = https.request( url, options, json_handler );
console.log( 'has the request been sent yet?' );
request.end();

options = {
    method:'GET',
    host: 'jsonplaceholder.typicode.com',
    path: '/users?_limit=1',
    headers: {
	'Accept': '*/*'
    }
};
// no URL argument
request = https.request( options, json_handler );
request.on( 'error', err_handler );
request.end();


let newUser = {
    name: 'Drexl Spivey',
    username: 'drexl',
    email: 'donotreply@example.com',
    address: {
	street: 'Oak Hill',
	city: 'Melrose',
	zipcode: '02134'
    },
    phone: '888-555-1212'
};

options = {
    method:'POST',
    host: 'jsonplaceholder.typicode.com',
    path: '/users',
    headers: {
	'Accept':       'application/json',
	'Content-Type': 'application/json; charset=UTF-8'
    }
};
// no URL argument
request = https.request( options, post_handler );
request.on( 'error', err_handler );
request.write( JSON.stringify(newUser) );
request.end();


let updates = {
    username: 'spiv',
};

options = {
    method:'PUT',
    host: 'jsonplaceholder.typicode.com',
    path: '/users/9',
    headers: {
	'Accept':       'application/json',
	'Content-Type': 'application/json; charset=UTF-8'
    }
};
// no URL argument
request = https.request( options, json_handler );
request.on( 'error', err_handler );
request.write( JSON.stringify(updates) );
request.end();


options = {
    method:'DELETE',
    host: 'jsonplaceholder.typicode.com',
    path: '/users/1',
    headers: {
	'Accept':       'application/json'
    }
};
// no URL argument
request = https.request( options, json_handler );
request.on( 'error', err_handler );
request.end();



