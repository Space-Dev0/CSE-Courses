#include <iostream>

class a; // forward declaration

class b
{
public:
    void display(a &obj);
};

class a
{
private:
    int age;
    std::string name;
    friend void b::display(a &obj);

public:
    a(std::string nam, int a)
    {
        name = nam;
        age = a;
    }
};

// outclass definition of member friend function is only allowed
void b::display(a &obj)
{
    std::cout << "Name: " << obj.name << "\nAge: " << obj.age << "\n";
}

int main()
{
    a student("Kanishak", 12);
    b cb;
    cb.display(student);
}
