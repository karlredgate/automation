
const Browser = require('zombie');

var browser = new Browser();

function done() {
    browser.assert.success();
    console.log( browser.location.href );
console.log( browser.window._response.body );
console.log( browser.window._document );
    browser.assert.text('title','Junk');
}

browser.visit( 'https://www.google.com/', done );
