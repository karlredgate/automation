
const EventSource = require('eventsource');
let es = new EventSource('http://localhost:3000/events');

es.onerror = function (err) {
    console.log( "ERR: " + err.status );
    if (err) {
        if (err.status === 401 || err.status === 403) {
            console.log('not authorized');
        }
    }
};

function listener( event ) {
    console.log( 'EVENT' );
    console.log( event );
    console.log( event.data );
}

// x.onmessage = function (e) { console.log( e.data ); };
es.addEventListener('server-time', listener );

// while ( es.readyState === 0 ) { console.log( "wait" ); }
console.log( 'started ' + es.readyState );
