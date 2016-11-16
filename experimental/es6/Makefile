
test: translate
	npm run-script translate spread.es6 | node

translate: devenv quux.es5 import-module.es5 spread.es5

%.es5: %.es6
	npm run-script translate $^ > $@

devenv:
	npm install
