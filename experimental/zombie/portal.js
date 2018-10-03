
const Browser = require('zombie');

var browser = new Browser();

function done() {
    browser.assert.success();
    console.log( browser.location.href );
//  https://control.akamai.com/apps/auth/
}

browser.visit( 'https://control.akamai.com/', done );
