#include <iostream>

template <typename T1, typename T2>
auto print(T1 a, T2 b)
{
    // std::cout << a > b ? a : b;
    return a > b ? a : b;
}

int main()
{
    std::cout << print(1, 2) << "\n";
    std::cout << print(23421343456789, 4u) << "\n";
    std::cout << print(345, 234.3) << "\n";

    std::string str1 = "EDFREGT", str2 = "dvrevre";
    std::cout << print(str1, str2) << "\n";
}