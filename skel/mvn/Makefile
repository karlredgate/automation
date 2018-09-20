
default: pom.xml
	mvn -e validate

doc: pom.pdf

pom.pdf: pom.tex
	lualatex pom.tex
	makeindex -s pom.ist pom.idx
	lualatex pom.tex

pom.xml: pom.fw
	fw pom.fw || ( cat pom.lis ; exit 1 )

pom.tex: pom.fw
	fw pom.fw +t

clean: pom.xml
	mvn clean
	rm -f pom.aux pom.idx pom.lis pom.log pom.nop pom.pdf pom.tex pom.toc pom.xml pom.ilg pom.ind
