#include <iostream>
#include <vector>

int main()
{
    std::vector<int> A = {1, 2, 3}, B = {1, 2, 3};

    if (A == B)
    {
        std::cout << "Vectors are same ";
    }
}