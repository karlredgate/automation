#!/usr/bin/env node

const Path = require('path');
const Express = require('express');
const BodyParser = require('body-parser');
const SQLite = require('sqlite3');

function bad_request( response ) {
    response.status( 400 );
    response.send( '{"error": "invalid"}' );
    response.end();
}

function is_invalid( request ) {
    if ( typeof request.body.metrics == 'undefined' ) return true;
    if ( typeof request.body.dataset == 'undefined' ) return true;
    // check "name", "frequency", "filters", "group by"
    if ( typeof request.query.wafconfig == 'undefined' ) {
        // Check if there are more than one for this account
        console.log( "missing wafconfig" );
        return true;
    }
    return false;
}

function find_config( request, response, next ) {
    if ( typeof request.query.wafconfig == 'undefined' ) {
        // Check if there are more than one for this account
        console.log( "missing wafconfig" );
        return next();
    }
    console.log( "Look for " + request.query.wafconfig );
    // lookup config object
    next();
}

// ?wafconfig=NNN
function timeseries( request, response ) {
    console.log( "BODY: " + JSON.stringify(request.body) );
    var data = {
        "data": [1,2,3],
        "request": request.body
    };

    if ( is_invalid(request) ) {
        bad_request( response );
        return;
    }

    response.status( 200 );
    response.set( 'Content-Type', 'application/json' );
    response.end( JSON.stringify(data) );
}

function dataseries( request, response ) {
    response.end( 'DATA' );
}

// Change so it errors with wrong content type
//
function registerAPIs( app ) {
    var parser = BodyParser.json( {type: ['application/json', 'application/*+json']} );
    app.use( parser );
    app.use( find_config );

    // app.post( '/appsec-securitycenter-api/websvc/v1/timeseries', parser, timeseries );
    app.post( '/appsec-securitycenter-api/websvc/v1/timeseries', timeseries );
    app.get( '/appsec-securitycenter-api/websvc/v1/dataseries', dataseries );
}

function connected() {
    console.log( "server started" );
}

function main( argv ) {
    var db = new SQLite.Database('extapi.db');
    db.close();

    var port = 3200;
    var app = Express();

    app.disable( 'x-powered-by' );
    registerAPIs( app );
    var content = Path.join( __dirname, "/static/" );
    app.use( Express.static(content) );
    app.listen( port, connected );
}

main( process.argv );

// vim: autoindent expandtab sw=4
