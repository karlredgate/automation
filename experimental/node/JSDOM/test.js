
// JSDOM requires this - but by def it generates an error.
//   const utf8Encoder = new TextEncoder();
//   ReferenceError: TextEncoder is not defined
// Do this to bypass the error

const util = require('util');
global.TextEncoder = util.TextEncoder;
global.TextDecoder = util.TextDecoder;

const jsdom = require('jsdom');
const { JSDOM } = jsdom;

const dom1 = new JSDOM( "<html><body><p>testing jsdom</p></body></html>" );

console.log( dom1.window.document.querySelector("p").textContent );
