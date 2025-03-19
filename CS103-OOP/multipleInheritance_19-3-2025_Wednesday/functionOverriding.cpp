#include <iostream>

class A
{
    int x = 10;

public:
    void display()
    {
        std::cout << x << "\n";
    }
};

class B : public A
{
protected:
    int y = 100;

public:
    void display()
    {
        std::cout << y << "\n";
    }
};

int main()
{
    B obj;
    obj.display();
    obj.A::display();
}