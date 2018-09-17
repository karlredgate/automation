#!/usr/bin/env node
#
# How to read from file arg on cmd line - or stdin
# This is only using synnc read

var filename = process.argv[2] || '/dev/stdin';

const fs = require('fs');

o = JSON.parse( fs.readFileSync(filename) );
