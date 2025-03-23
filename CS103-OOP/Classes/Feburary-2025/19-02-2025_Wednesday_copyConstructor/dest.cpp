#include <iostream>

class student
{
private:
    std::string stud;
    int age;

public:
    student()
    {
        stud = "Mittal";
        age = 18;
        std::cout << "Constructor evoked\n";
    }
    ~student()
    {
        std::cout << "Destructor evoked\n";
    }
    void display()
    {
        std::cout << stud << "\t" << age << "\n";
    }
};

int main()
{
    student s;
    s.display();
}