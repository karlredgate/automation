default: dependencies
	node --experimental-modules junk.mjs
	# node test.js

dependencies:: node_modules/react/package.json
dependencies:: node_modules/react-dom/package.json
dependencies:: node_modules/jsdom/package.json
dependencies:: node_modules/enzyme/package.json
dependencies:: node_modules/enzyme-adapter-react-16/package.json

node_modules/jsdom/package.json:
	npm install jsdom

node_modules/enzyme/package.json:
	npm install enzyme

node_modules/react/package.json:
	npm install react

node_modules/react-dom/package.json:
	npm install react-dom

node_modules/enzyme-adapter-react-16/package.json:
	npm install enzyme-adapter-react-16

clean:
	rm -rf node_modules
