#include <iostream>
#include <list>

int main()
{
    std::list<char> L = {'m', 'a', 'l', 'a', 'y', 'a', 'l', 'a', 'm'};
    std::list L2 = L;
    L2.reverse();
    if (L == L2)
        std::cout << "Pallindrome! \n";
    else
        std::cout << "Not Pallindrome! \n";

    std::list<char>::iterator end = L.end();
    end--;
    std::list<char>::iterator front = L.begin();

    while ((*end == *front) && (end != front))
    {
        end--;
        front++;
    }

    if (end == front)
        std::cout << "Pallindrome! \n";
    else
        std::cout << "Not Pallindrome! \n";
}