#include <iostream>

class A
{
private:
    int x = 10;

public:
    void func(int x, int y)
    {
        this->x = x + y;
        display();
    }

    virtual void display()
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
    A *ptr;
    B obj;
    ptr = &obj;
    ptr->func(12, 23);
    ptr->A::display();
}