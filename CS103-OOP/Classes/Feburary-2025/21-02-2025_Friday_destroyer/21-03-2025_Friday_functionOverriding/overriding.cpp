#include <iostream>

/*
 * Static Binding    -  Compile time binding
 *                      Binds functions to each other during compile time
 *
 * Dynamic Binding   -  Runtime binding
 *                      Binds functions during runtime
 */

class A
{
private:
    int x = 10;

public:
    void func(int x, int y)
    {
        this->x = x + y; // 'this' is used to remove ambiguity or name collisions
                         // it tells that the variable belongs to this class
        display();
    }

    virtual void display() // Virtual keyword explicitly says this
                           // function will be overriden
    {
        std::cout << x << "\n";
    }
};

class B : public A
{
protected:
    int y = 100;

public:
    void display() override // 'override' keyword tells that this function
                            // will be overriden
    {
        std::cout << y << "\n";
    }
};

int main()
{
    B objB;
    A objA;
    objA.func(12, 23);
    objB.func(12, 23);
    objB.A::display();
}