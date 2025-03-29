#include <iostream>

template <typename U>
class MyClass
{
private:
    U data;

public:
    MyClass(const U var) : data(var) {}

    template <typename T, typename P>
    friend void show(MyClass<T> &obj1, MyClass<P> &obj2);

    template <typename T>
    void get(T var);
};

template <typename T, typename P>
void show(MyClass<T> &obj1, MyClass<P> &obj2)
{
    std::cout << "Sum is: " << obj2.data + obj1.data << "\n";
}

int main()
{
    MyClass M(2);
    MyClass P(34.32);
    show(M, P);
}