#include <map>
#include <vector>
#include <iostream>

int main()
{
    std::map<std::string, std::vector<int>> map;

    map["Kanishak"] = std::vector<int>{12, 23, 34, 45};
    map["Mittal"] = std::vector<int>{13, 45, 53};
    map["DDDDD"] = std::vector<int>{134, 23, 54};
    map["dv d sd"] = std::vector<int>{121, 23, 4, 5};

    for (auto &&i : map)
    {
        std::cout << i.first << " => " << "{";

        for (auto &&j : i.second)
            std::cout << j << ", ";
        std::cout << "\b\b}\n";
    }
}
