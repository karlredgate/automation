
env JAVA_HOME=$( /usr/libexec/java_home )

test: HelloWorld.class HelloTrait.class SingletonObject.class
	scala-2.12 HelloWorld
	scala-2.12 HelloTrait
	scala-2.12 CallSingletonObject

HelloTrait.class: HelloTrait.scala
	scalac-2.12 HelloTrait.scala 

HelloWorld.class: hello.scala
	scalac-2.12 hello.scala 

SingletonObject.class: SingletonObject.scala
	scalac-2.12 SingletonObject.scala 

clean:
	rm *.class
