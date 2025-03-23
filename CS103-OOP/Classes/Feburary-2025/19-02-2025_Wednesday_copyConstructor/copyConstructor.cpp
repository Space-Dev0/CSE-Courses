#include <iostream>

class student
{
public:
    std::string stud;
    int age;

    student()
    {
        stud = "Ramesh";
        age = 37;
    }
    student(std::string name, int a)
    {
        stud = name;
        age = a;
    }
    student(const student &obj){
        stud = obj.stud;
        age = obj.age;
    }
    void display()
    {
        std::cout << stud << "\t" << age << "\n";
    }
};

int main()
{
    student s1, s2, s3("Mittal", 18);
    s1.display();
    s2.display();
    s3.display();
    student s4(s3);
    s4.display();
    return 0;
}