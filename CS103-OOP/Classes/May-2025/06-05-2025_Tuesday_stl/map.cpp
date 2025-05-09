#include <iostream>
#include <map>
#include <queue>
#include <bits/stdc++.h>
/*
 *  Syntax for making maps
 *
 *                    Map From T to U
 *                     |           |
 *                     v           v
 *  std::map <Typename T, Typename U> Identifier;
 *
 *
 *
 * */

int main()
{
    std::map<double, int> doubleToInt = {{12.1, 1}, {12.3, 4}, {12.1, 3}};
    doubleToInt.insert({12.5, 4});
    std::cout << doubleToInt[10] << "\n";
    std::cout << doubleToInt.count(12.1) << "\n";
    doubleToInt.erase(10);

    std::cout << "Map: \n";
    for (auto &&i : doubleToInt)
    {
        std::cout << i.first << " ==> " << i.second << "\n";
    }
    std::cout << doubleToInt.find(12.3)->second << "\n";
}
