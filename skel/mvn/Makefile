
default: pom.xml
	mvn -e validate

doc: pom.pdf

pom.pdf: pom.tex
	lualatex pom.tex
	lualatex pom.tex

pom.xml: pom.fw
	fw pom.fw

pom.tex: pom.fw
	fw pom.fw +t

clean:
	mvn clean
	rm -f pom.aux pom.idx pom.lis pom.log pom.nop pom.pdf pom.tex pom.toc pom.xml
