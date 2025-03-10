#include <iostream>

class number
{
public:
    int num;

    number(int n) : num(n) {}

    void operator+(number num2)
    {
        std::cout << num << "+" << num2.num << "=" << num + num2.num << "\n";
    }

    void operator-(number num2)
    {
        std::cout << num << "-" << num2.num << "=" << num - num2.num << "\n";
    }

    void operator*(number num2)
    {
        std::cout << num << "*" << num2.num << "=" << num * num2.num << "\n";
    }

    void operator/(number num2)
    {
        std::cout << num << "/" << num2.num << "=" << num / num2.num << "\n";
    }

    void operator%(number num2)
    {
        std::cout << num << "%" << num2.num << "=" << num % num2.num << "\n";
    }
};

int main()
{
    number a{23}, b{2};
    a + b;
    a - b;
    a *b;
    a / b;
    a % b;
}