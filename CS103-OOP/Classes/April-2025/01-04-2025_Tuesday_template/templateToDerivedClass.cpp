#include <iostream>

class ClassA
{
private:
    int x, y;

public:
    ClassA() {}
    ClassA(int a, int b) : x(a), y(b) {}
    void display()
    {
        std::cout << "x = " << x << " ,y = " << y << "\n";
    }
};

template <typename T>
class ClassB : public ClassA
{
private:
    T data;

public:
    ClassB(T B) : data(B) {};

    void display()
    {
        data.display();
    }
};

int main()
{
    ClassA A1(12, 34);
    ClassB B1(A1);
    B1.display();
}