#include <iostream>
#include <set>

// Set is a balanced binary search tree

int main()
{
    std::set<int> nums = {12, 33, 12, 43, 56};

    std::cout << "Size: " << nums.size() << "\n";

    nums.insert(12);
    nums.insert(34);
    std::cout << "Inserting 12, 13\n";

    std::cout << "Set: ";
    for (auto &&i : nums)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Removing 12 , 45\n";
    nums.erase(12);
    nums.erase(45);

    std::cout << "Set: ";
    for (auto &&i : nums)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}