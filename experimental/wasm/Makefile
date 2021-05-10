
test: hello.wasm
	node-v9.4.1 hello.js

hello.wasm: hello.c
	node_modules/.bin/wa compile -o hello.wasm hello.c

