#include <iostream>

class B;
template <typename T>
class ClassA
{
private:
    T data;
    friend class ClassB;

public:
    ClassA(T d) : data(d) {}
    void display()
    {
        std::cout << "Data: ", data;
    }
};

class ClassB
{
private:
    std::string str = "Hello, World!\n";

public:
    template <typename T>
    void display(ClassA<T> &obj)
    {
        std::cout << str << obj.data << "\n";
    }
};

int main()
{
    ClassA A1(234);
    ClassA A2(32.23);
    ClassA A3(100100u);
    ClassA A4("Mittal");

    ClassB B;

    B.display(A1);
    B.display(A2);
    B.display(A3);
    B.display(A4);

    return 0;
}