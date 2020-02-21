
PROJECT=Command
JAR=$(PROJECT).jar
OBJS += $(PROJECT).class

test: $(JAR)
	@: java Command
	java -jar $(JAR) /foo/\*/bar/baz/quux

$(JAR): $(OBJS)
	jar cfm $@ Manifest.txt $(OBJS)

%.class: %.java
	javac $?

clean:
	rm -f *.class *.jar
