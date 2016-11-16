
function getFile( url ) {
    return fetch(url)
           .then( request => request.text() );
}
