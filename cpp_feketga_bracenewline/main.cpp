#include <iostream>
#include <type_traits>

namespace N1
{

struct A {};

struct B : A
{
private:
    int i;
public:
    B() : A() {}
};

template<typename T>
concept CallableReturnsInt = std::is_invocable_r<int, T>::value;

template<CallableReturnsInt TF>
int templateFunc(TF callback)
{
    return callback();
}

}

int main(int argv, char** argc)
{
    std::cout
        << "Hello"
        << " World"
        << argc << std::endl;

    N1::templateFunc([]() { return 1; });

    return 0;
}
