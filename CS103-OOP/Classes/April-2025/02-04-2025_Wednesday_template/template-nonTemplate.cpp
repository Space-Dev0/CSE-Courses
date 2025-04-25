#include <iostream>

template <typename T>
class ClassA
{
protected:
    T data;

public:
    ClassA(T d) : data(d) {}

    void display()
    {
        std::cout << "Data: " << data << "\n";
    }
};

class ClassB : public ClassA<double>
{
private:
public:
    ClassB(double a) : ClassA(a) {}
    void show()
    {
        std::cout << "Data: " << data << "\n";
    }
};

int main()
{
    ClassA A(1234.34);
    A.display();
    ClassB B1(1324.324);
    B1.show();
}