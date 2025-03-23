#include <iostream>

/*  Multiple inheritance Derived class syntax:
 *
 *
 *   class <Class_Derived_Name> :
 *   [Access specifier] <1_base_class_name>, [Access specifier] <2_base_class_name> ...{
 *
 *   Class Contents
 *
 *   };
 *
 */

/*
 *                         Person name salary age experience
 *
 *                        Employee empID
 *
 *                  Manger (Dept)  Engineer
 *                                  Hardware Software
 *
 *                             Projects
 *
 *
 */

using namespace std;

class Person
{
protected:
    string name;
    double salary;
    int age;
    int experience;

public:
    Person()
    {
        cout << "Enter the name, salary, age, experience: ";
        cin >> name >> salary >> age >> experience;
    }
    void display()
    {
        cout << "Name: " << name << "\nSalary: " << salary << "\nAge: " << age
             << "\nExperience: " << experience << "\n";
    }
};

class Employee : protected Person
{
private:
    string empID;

public:
    Employee()
    {
        cout << "Enter employee ID: ";
        cin >> empID;
    }
    void displayEID()
    {
        display();
        cout << "Employee Id :" << empID << "\n";
    }
};

class Manager : protected Employee
{
private:
    string department;

public:
    Manager()
    {
        cout << "Enter department: ";
        cin >> department;
    }
    void dspDprt()
    {
        display();
        cout << "Department :" << department << "\n";
    }
};

class Engineer : protected Employee
{
private:
    string category;

public:
    Engineer()
    {
        cout << "Enter category: ";
        cin >> category;
    }
    void dspDprt()
    {
        display();
        displayEID();
        cout << "Category :" << category << "\n";
    }
};
