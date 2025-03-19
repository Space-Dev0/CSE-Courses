#include <iostream>

/*
 *  Inheritance is a "is a" relation, Example:
 *  - Car is a Vehicle
 *  - Bike is a Vehicle
 */

/*  Single level Derived class syntax:
 *
 *
 *   class <Class_Derived_Name> : [Access specifier] <base_class_name>{
 *
 *   Class Contents
 *
 *   };
 *
 */

// Constructors, Destructors, Friend function, Operator overloads are not inherited

/*
 *  Constructor works from top to bottom:
 *
 *              First : Parent
 *             Second : Child
 *              Third : GrandChild
 *                :         :
 *                :         :
 *
 *
 *  Destructor works from bottom to top:
 *
 *              First : GrandChild
 *             Second : Child
 *              Third : Parent
 *                :       :
 *                :       :
 */

class A
{
private:
    int age;
    std::string name;

public:
    A()
    {
        std::cout << "Enter name and age: ";
        std::cin >> name >> age;
    }
    ~A()
    {
        std::cout << "Destructor of A called\n";
    }
};

class B : public A
{
protected:
    int salary;

public:
    B()
    {
        std::cout << "Enter salary: ";
        std::cin >> salary;
    }
    ~B()
    {
        std::cout << "Destructor of B called\n";
    }
};

int main()
{
    B obj;
}