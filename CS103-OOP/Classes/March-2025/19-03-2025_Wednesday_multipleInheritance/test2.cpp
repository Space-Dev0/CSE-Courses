#include <iostream>
#include <iomanip>
class person
{
protected:
    int age;
    std::string name;
    float height;

public:
    person(int ag, std::string nam, float hg) : age(ag), name(nam), height(hg) {}

    void show()
    {
        std::cout << "Age: " << age << "\n"
                  << "Name: " << name << "\n"
                  << "Height: " << height << "\n";
    }
};

class employee
{
protected:
    int emp_id;
    double salary;

public:
    employee(int emp, double sa) : emp_id(emp), salary(sa) {}

    void show()
    {
        std::cout << "Employee Id: " << emp_id << "\n"
                  << "Salary: " << salary << "\n";
    }
};

class manager : public person, private employee
{
protected:
    std::string dept;

public:
    manager(int ag, std::string nam, float hg, int emp, double sa, std::string de) : dept(de), employee(emp, sa), person(ag, nam, hg) {}
    void show()
    {
        person::show();
        employee::show();
        std::cout << "Department: " << dept << "\n";
    }
};

int main()
{
    std::cout << std::scientific;      // Changes into exponential form
    std::cout << std::setprecision(2); // Changes the precision of floating point of cout
    manager M1(23, "Kan", 23.2, 234, 2345.3, "CSE");
    M1.person::show();
    M1.show();
}