#include <iostream>

// To solve diamond problem
// use virtual keyword to make a pointer connection avoiding multiple copies

class A
{
protected:
    int Aa;

public:
    //A() { std::cout << "Constructor of A called\n"; }
    A(int a) : Aa(a) { std::cout << "Constructor of A called\n"; }
};

class B : virtual protected A
{
protected:
    int Bb;

public:
    B(int a, int b) : Bb(a), A(b) { std::cout << "Constructor of B called\n"; }
};

class C : virtual protected A
{
protected:
    int Cc;

public:
    C(int c, int d) : Cc(c), A(d) { std::cout << "Constructor of C called\n"; }
};

class D : protected B, protected C
{
public:
    D(int a, int b, int c, int d) : B(a, b), C(c, d)
    {
        std::cout << "Constructor of D called\n";
    }
    void print()
    {
        std::cout << Bb << "  "
                  << Aa << "  "
                  << C::Aa << "  "
                  << Cc << "  ";
    }
};

int main()
{
    D obj(1, 2, 3, 4);
    obj.print();
}