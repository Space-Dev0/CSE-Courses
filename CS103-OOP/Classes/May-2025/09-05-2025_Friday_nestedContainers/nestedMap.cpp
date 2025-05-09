#include <iostream>
#include <map>

int main()
{
    std::map<std::map<double, std::string>, int> weirdMap;

    std::map<double, std::string> tempMap;
    tempMap.emplace(12.234, "dfvh");
    tempMap.emplace(123.23, "cfvg htjy");

    weirdMap.emplace(tempMap, 12234);

    tempMap.clear();

    tempMap[4657.4] = "DSFG";
    tempMap[324.23] = "VFBG";
    tempMap[46.4] = "swd";

    weirdMap.emplace(tempMap, 456);

    for (auto &&i : weirdMap)
    {
        for (auto &&j : i.first)
        {
            std::cout << j.first << "=>" << j.second << "=>" << i.second << "\n";
        }
    }
}