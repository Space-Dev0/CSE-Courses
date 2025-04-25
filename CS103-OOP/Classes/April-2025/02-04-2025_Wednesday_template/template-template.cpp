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
        std::cout << "Data 1: " << data << "\n";
    }
};

template <typename T, typename U>
class ClassB : public ClassA<U>
{
private:
    T data;

public:
    ClassB(T d, U f) : data(d), ClassA<U>(f) {}
    void display()
    {
        std::cout << "Data 2: " << data << "\n";
    }
    void sum()
    {
        std::cout << "Sum: " << data + ClassA<U>::data << "\n";
    }
};

int main()
{
    std::string str1{"Kanishak"}, str2{" Mittal"};
    ClassB B(str1, str2);
    B.sum();
    B.display();
    B.ClassA::display();
}