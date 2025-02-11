#include <iostream>

int main()
{
    int num;
    std::cout << "Enter num: ";
    std::cin >> num;
    int numCopy = num;
    int binary = 0;
    for (int i = 0; num > 0; i++)
    {
        // binary = num % 2;
        // binary = binary*10 + num%2;
        // num /= 2;
        std::cout << num % 2;
        num = num / 2;
    }
    // std::cout << "Binary of " << numCopy << " is: " << binary << "\n";
}