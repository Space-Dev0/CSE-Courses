#include<iostream>
#include<string>
using namespace std;
class student
{
    private:
        int age;
        string name, roll_no;
    
    public:
    void display();
    void student_name(string nam)
    {
        name = nam;
    }
    

};
void student:: display()
{
    cout<< "The student name and roll numbers are "<< name << roll_no << ", age is "<<age;
}
int main()
{
    student s1;
    s1.student_name("Ramesh");
    s1.display();
}