
PACKAGE = packagename
PWD := $(shell pwd)
DEPENDENCIES = tcl iconv

default: dependencies package

OS := $(shell uname -s)

include Makefiles/$(OS).mk

dependencies: distro_dependencies
	@echo "Dependencies checked"

package: dist distro_package
	@echo "Created $(PACKAGE) package for $(DISTRO)"

dist: build
	: mkdir -p dist/usr/bin
	: cp bin/* dist/usr/bin
	: mkdir -p dist/usr/share/pathologist/diagnostics
	: cp diagnostics.rdf dist/usr/share/pathologist/diagnostics/
	: mkdir -p dist/usr/libexec/pathologist/diagnostics
	# tar cf - libexec/pathologist/diagnostics/ | tar -xf - -C dist/usr

build: distro_build

TESTDB=testdata
test: distro_test
	xsltproc diagscript.xslt diagnostics.rdf | sudo bash
	-rdfproc $(TESTDB) parse diagnostics.rdf
	-rapper --count diagnostics.rdf

clean: distro_clean
	rm -f $(TESTDB)*.db
	rm -rf dist
