#include <iostream>
#include <vector>
#include <algorithm>

void getIntList(std::vector<int> &A)
{
    A.resize(0);
    int val;
    while (std::cin >> val)
    {
        A.push_back(val);
    }
}

int main()
{
    std::vector<int> list;
    std::cout << "Enter numbers: ";
    getIntList(list);

    for (auto &&i : list)
    {
        std::cout << i << " ";
    }
}
