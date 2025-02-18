#include<iostream>
using namespace std;

class student
{
    public:
        string name,roll_no;
        int age;
    student()
    {
        name = "Ramesh";
        age=30;
        cout<<"I'm in default constructor"<<endl;
    }
    student(string rno)
    {
        roll_no = rno;
        cout<<"I'm in the constructor with one parameter"<<endl;
    }
    student(string nam, string rno, int a)
    {
        name = nam;
        roll_no = rno;
        age = a;
        cout<<"I'm in third constructor"<<endl;
    }
    void display()
    {
        cout<<"Student name is: "<< name << " Roll number is: "<< roll_no << " The age is: "<< age<<endl;
    }

};

int main()
{
    student s1,s2("csb20221"),s3("Suresh","CSb3535",56);
    s1.display();
    s2.display();
    s3.display();
    return 0;

}