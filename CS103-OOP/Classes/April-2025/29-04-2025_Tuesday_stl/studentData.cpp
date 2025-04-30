#include <iostream>
#include <sstream>
#include <vector>

class StudentData
{
private:
    std::string name;
    int age;
    std::string gender;

public:
    StudentData(std::string nam, int ag, std::string gen) : name(nam), age(ag), gender(gen) {}

    void print()
    {
        std::cout << "Name = " << name << "\n"
                  << "Age = " << age << "\n";

        if (gender == "M" || gender == "m")
            std::cout << "Gender = Male\n";

        else if (gender == "f" || gender == "F")
            std::cout << "Gender = Female\n";

        else
            std::cout << "Gender = " << gender << "\n";
    }
};

void input(std::vector<StudentData> &sData, size_t *i)
{
    while (1)
    {
        std::string name;
        std::string gender;
        int age;
        std::cout << "Enter Name for Student " << *i << " : ";
        std::getline(std::cin, name);
        if (name == "exit")
            break;
        std::cout << "Enter age: ";
        if (!(std::cin >> age))
            break;
        std::cout << "Enter gender: ";
        std::cin >> gender;
        if (gender == "exit")
            break;

        std::cin.ignore(1);
        sData.push_back(StudentData(name, age, gender));
        (*i)++;
    }
}

int main()
{
    std::vector<StudentData> sData;
    size_t i = 0;
    input(sData, &i);
    while (1)
    {
        std::string indexStr;

        std::cin.clear();
        std::cin.ignore(1000, '\n');

        std::cout << "\nYou have data of " << i << " Students\n"
                  << "Enter index of student to view data,\n"
                  << "Enter \"+in\" to add more data,\n"
                  << "any other to exit: ";

        std::cin >> indexStr;
        std::stringstream stream(indexStr);
        size_t index;

        if (indexStr == "+in")
        {
            std::cin.ignore(1);
            input(sData, &i);
            continue;
        }

        if (!(stream >> index))
            break;
        if (index >= i)
        {
            std::cout << "err: Out of range !\n";
            continue;
        }
        std::cout << "Data of student at index " << index << "\n";
        sData[index].print();
        continue;
    }
}