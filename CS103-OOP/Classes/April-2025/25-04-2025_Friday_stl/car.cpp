#include <iostream>
#include <vector>

int main()
{

    std::vector<std::string> brand;
    std::cout << "Enter number of brands: ";
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        std::string temp;
        std::cout << "Enter Brand: ";
        std::cin >> temp;
        brand.push_back(temp);
    }

    std::cout << "List: ";
    // for (auto &&i : brand)
    // {
    //     std::cout << i << " ";
    // }

    for (int i = 0; i <= brand.size(); i++)
    {
        std::cout << brand.at(i) << " ";
    }
}