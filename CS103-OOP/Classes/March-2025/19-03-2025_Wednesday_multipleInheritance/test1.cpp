#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "Constructor called of A\n";
    }
    void print()
    {
        std::cout << "I am in class A\n";
    }
};

class B
{
public:
    B()
    {
        std::cout << "Constructor called of B\n";
    }
    void print()
    {
        std::cout << "I am in class B\n";
    }
};

class C : public A, public B
{
public:
    C()
    {
        std::cout << "Constructor of C called: ";
    }
};

int main()
{
    C obj;

    // To solve the problem of ambiguity use ::
    obj.A::print();
    obj.B::print();
    return 0;
}