
# Make - Maven? - Grunt?

URL=http://mirror.cc.columbia.edu/pub/software/apache//velocity/engine/1.7/velocity-1.7.tar.gz
TARBALL=velocity-1.7.tar.gz
JAR=velocity-1.7/velocity-1.7.jar
DEPJAR=velocity-1.7/velocity-1.7-dep.jar

test: ClubApp.txt

ClubApp.class: ClubApp.java $(JAR)
	javac ClubApp.java -classpath $(JAR)


ClubApp.txt: ClubApp.class ClubApp.vm $(DEPJAR)
	java -classpath $(JAR):$(DEPJAR):. ClubApp > $@

$(JAR): $(TARBALL)
	tar xmzf $^

$(DEPJAR): $(TARBALL)
	tar xmzf $^

$(TARBALL):
	wget $(URL)

clean:
	rm -f ClubApp.class ClubApp.txt
