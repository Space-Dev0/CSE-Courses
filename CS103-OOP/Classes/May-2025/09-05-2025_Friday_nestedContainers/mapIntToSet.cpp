#include <iostream>
#include <set>
#include <unordered_map>
#include <sstream>

int main()
{
    std::unordered_map<int, std::set<int>> map;

    while (1)
    {
        std::set<int> tempSet;
        std::cout << "Enter elements in set: ";
        std::string setStr;

        std::getline(std::cin, setStr);

        if (setStr.empty())
            break;

        std::stringstream s(setStr);
        int temp;
        while (s >> temp)
            tempSet.insert(temp);
        std::cout << "Enter integer to associate with set: ";
        int intToLink;
        std::cin >> intToLink;
        std::cin.ignore();
        map.emplace(intToLink, tempSet);
    }

    std::cout << "\nMap\n";
    for (auto &&i : map)
    {
        std::cout << i.first << " => " << "{";

        for (auto &&j : i.second)
            std::cout << j << ", ";
        std::cout << "\b\b}\n";
    }
}