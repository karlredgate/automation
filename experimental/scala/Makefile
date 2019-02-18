
test: HelloWorld.class HelloTrait.class
	scala-2.12 HelloWorld
	scala-2.12 HelloTrait

HelloTrait.class: HelloTrait.scala
	scalac-2.12 HelloTrait.scala 

HelloWorld.class: hello.scala
	scalac-2.12 hello.scala 

clean:
	rm *.class
