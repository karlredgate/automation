C++ Examples
============


Closure / Lambda
----------------

C++11 seems to allow closures

 * https://stackoverflow.com/questions/12483753/how-do-define-anonymous-functions-in-c
 * https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11

"Lambda functions are just syntactic sugar for anonymous functors."

clang on OSX requires:

```
clang++ -std=c++11 -stdlib=libc++ foo.cpp
```

G++ requires

```
g++ -std=c++11 foo.cpp
```

 * https://stackoverflow.com/questions/13752233/using-clang-with-libc-and-c11-from-the-command-line-with-mac-os-x
 * https://stackoverflow.com/questions/10363646/compiling-c11-with-g

Capture
-------

You can capture by both reference and value, which you can specify using & and = respectively:

 * `[&epsilon]`    capture by reference
 * `[&]`           captures all variables used in the lambda by reference
 * `[=]`           captures all variables used in the lambda by value
 * `[&, epsilon]`  captures variables like with [&], but epsilon by value
 * `[=, &epsilon]` captures variables like with [=], but epsilon by reference

It requires mutable because by default, a function object should
produce the same result every time it's called. This is the difference
between an object orientated function and a function using a global
variable, effectively.

 * https://stackoverflow.com/questions/5501959/why-does-c11s-lambda-require-mutable-keyword-for-capture-by-value-by-defau
 * http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3424.pdf
 * http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2011/n3242.pdf
 * https://en.wikipedia.org/wiki/Pure_function
 * https://en.wikipedia.org/wiki/Anonymous_function#C.2B.2B
 * https://github.com/spencertipping/bash-lambda

The anonymous function article from Wikipedia above shows
the gcc and clang extensions that provide closures.

Error when you don't provide the capture:

```
closure.cpp:18:58: error: variable 'i3' cannot be implicitly captured in a
      lambda with no capture-default specified
    auto f3 = []( int a, int b ) -> int { return a + b + i3; };
                                                         ^
closure.cpp:17:9: note: 'i3' declared here
    int i3 = 20;
        ^
closure.cpp:18:15: note: lambda expression begins here
    auto f3 = []( int a, int b ) -> int { return a + b + i3; };
              ^
1 error generated.
```
