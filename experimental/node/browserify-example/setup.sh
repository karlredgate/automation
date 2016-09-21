#!/bin/bash

npm install babel-cli
npm install browserify
npm install babelify
npm install babel-preset-es2015
npm install partialify

cat > .babelrc <<END
{ "presets":["es2015"]}
END

./node_modules/.bin/browserify -g babelify -g partialify junk.js

