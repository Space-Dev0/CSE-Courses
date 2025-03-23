#include <iostream>

class A
{
private:
    int age;
    char gender;
    friend class B;

public:
    A()
    {
        std::cout << "Enter age: ";
        std::cin >> age;
        std::cout << "Enter gender: ";
        std::cin >> gender;
    }
};

class B
{
private:
    std::string name;

public:
    B(std::string nam)
    {
        name = nam;
    }
    void display(A &obj)
    {
        std::cout << "The age and gender of " << name << " is "
                  << obj.age << ", " << obj.gender << "\n";
    }
};

int main()
{
    A a1;
    B b1("Kanishak");
    b1.display(a1);
}