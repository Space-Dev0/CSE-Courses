#include <iostream>

int main()
{
    int *a = new int(45);
    std::cout << "The value of a is " << *a << "\n";
    *a = 10;
    std::cout << "The value of a after assignment is " << *a << "\n";
    delete a;
    return 0;
}