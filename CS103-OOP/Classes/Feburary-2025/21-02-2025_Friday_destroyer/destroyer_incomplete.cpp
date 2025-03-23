#include <iostream>

class student
{
public:
    std::string name;
    int age;
    int count;
    student()
    {
        name = "Kanishak";
        age = 18;
        std::cout << "Constructor 1 evoked for "<< count++<<"\n";
    }
    student(std::string nam, int a)
    {
        name = nam;
        age = a;
        std::cout << "Constructor 2 evoked for "<< count++<<"\n";
    }
    ~student()
    {
        std::cout << "Destructor destroyed"
    }
    


};

int main
