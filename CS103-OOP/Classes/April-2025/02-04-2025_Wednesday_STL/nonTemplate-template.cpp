#include <iostream>

class ClassA
{
private:
    int num;

public:
    ClassA(int a) : num(a) {}
    void display()
    {
        std::cout << "Num = " << num << "\n";
    }
};

template <typename T>
class ClassB : public ClassA
{
private:
    T data;

public:
    ClassB(T a, int b) : data(a), ClassA(b) {}
    void display()
    {
        std::cout << "Data: " << data << "\n";
        ClassA::display();
    }
};

int main()
{
    std::string str = "SDSCFVGB";
    ClassB B(str, 234);
    B.display();
}