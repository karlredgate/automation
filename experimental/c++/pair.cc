
#include <utility>
#include <iostream>

int main( int argc, char **argv ) {
    std::pair<bool,int> foo(true, 3);
    std::cout << "First " << foo.first << " " << foo.second << '\n';
}
