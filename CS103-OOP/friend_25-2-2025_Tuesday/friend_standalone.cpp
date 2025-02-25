#include <iostream>

class student
{
private:
    std::string studentName;
    int age;
    friend void display(student &s); // friend function declaration

public:
    student()
    {
        studentName = "Ramesh";
        age = 37;
    }
    student(std::string name, int a)
    {
        studentName = name;
        age = a;
    }
};

void display(student &S) // friend function definition
{
    std::cout << "Name: " << S.studentName << "\nAge: " << S.age << "\n";
}

int main()
{
    student S1("Kanishak", 12);
    display(S1);
}