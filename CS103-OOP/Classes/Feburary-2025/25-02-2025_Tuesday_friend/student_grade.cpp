#include <iostream>

class student;

class grade
{
private:
    int marks[3];
    std::string gradeAssign(int marks[3]);
    std::string g;
    friend class student;

public:
    grade(int a, int b, int c);
    std::string giveGrade() { return g; }
    grade();
};

grade::grade(int a, int b, int c)
{
    marks[0] = a;
    marks[1] = b;
    marks[2] = c;
    g = gradeAssign(marks);
}
grade::grade()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Enter marks for Subject " << i + 1 << ":";
        std::cin >> marks[i];
    }
    g = gradeAssign(marks);
}
std::string grade::gradeAssign(int marks[3])
{
    int total;
    for (int i = 0; i < 3; i++)
        total += marks[i];
    double average = static_cast<double>(total) / 3;
    if (average > 70)
        return "A+";
    else if (average > 60)
        return "A";
    else if (average > 50)
        return "B+";
    else
        return "B";
}

class student
{
private:
    std::string name;
    std::string roll_no;
    int age;
    grade g1;

public:
    student();
    student(std::string nam, std::string roll, int a);
    void display();
};

void student::display()
{
    std::cout << "Name: " << name << "\nRoll No.: " << roll_no << "\nGrade: " << g1.giveGrade() << "\n";
}

student::student()
{
    std::cout << "Enter student name: ";
    std::cin >> name;
    std::cout << "Enter student roll no: ";
    std::cin >> roll_no;
    std::cout << "Enter age: ";
    std::cin >> age;
}

student::student(std::string nam, std::string roll, int a)
{
    name = nam;
    roll_no = roll;
    age = a;
}

int main()
{
    student s1;
    s1.display();
}