
PROJECT=Command
OBJS += $(PROJECT).class

test: $(OBJS)
	@: java Command
	java -jar $(PROJECT).jar 

$(PROJECT).jar: $(OBJS)
	jar cfm $@ Manifest.txt $(OBJS)

%.class: %.java
	javac $?
