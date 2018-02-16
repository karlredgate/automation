var sqlite3 = require('sqlite3').verbose();
var db = new sqlite3.Database(':memory:');

function q1() {
	db.run( "create table lorem (id int)" );
}

db.serialize( q1 );
