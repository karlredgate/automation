
object SingletonObject {
    def greet() {
        println( "Hello SingletonObject" )
    }
}

object CallSingletonObject {
    def main( args: Array[String] ) : Unit = {
        SingletonObject.greet()
    }
}
