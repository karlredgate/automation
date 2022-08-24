
var Defer = function () {
    this.promise = new Promise();
};
Defer.prototype = {
    promise = null
};

Defer.prototype.resolve = function (data) {
    var handler = function (callback) {
	var wrapper = function () { callback(data); };
	setTimeout( wrapper, 0 );
    };
    this.promise.success.forEach( handler );
};
Defer.prototype.reject = function (error) {
    var handler = function (callback) {
	var wrapper = function () { callback(error); };
	setTimeout( wrapper, 0 );
    };
    this.promise.failure.forEach( handler );
};

var Promise = function () {
    this.success = [];
    this.failure = [];
};

Promise.prototype = {
    success = null,
    failure = null
};

Promise.prototype.then = function (good, err) {
    var defer = new Defer();
    success.push( good );
    if ( err ) {
	failure.push( err );
    }
};

// async and await ?
