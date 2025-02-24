#include <iostream>

class Calculator
{
private:
    int num1;
    int num2;
    char ch{};

public:
    Calculator();
    double divide(int a, int b);
    ~Calculator();
};

Calculator::Calculator()
{
    std::cout << "Enter expression: ";
    std::cin >> num1;
    if (0 > num1 || num1 > 1000)
    {
        std::cout << "Error: Invalid inputs!\n";
        return;
    }
    std::cin >> ch;
    if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
    {
        std::cout << "Error: Invalid operator!\n";
        return;
    }
    std::cin >> num2;
    if (1 > num1 || num1 > 1000)
    {
        std::cout << "Error: Invalid inputs!\n";
        return;
    }

    switch (ch)
    {
    case '+':
        std::cout << "Result: " << num1 + num2;
        break;
    case '-':
        std::cout << "Result: " << num1 - num2;
        break;
    case '*':
        std::cout << "Result: " << num1 * num2;
        break;
    case '/':
        if (num2 == 0)
        {
            std::cout << "Error: Division by zero!";
            break;
        }
        std::cout << "Result: "<< divide(num1, num2);
        break;
    default:
        break;
    }
    std::cout << "\n";
}

double Calculator::divide(int a, int b)
{
    return static_cast<double>(a) / b;
}

Calculator::~Calculator()
{
    std::cout << "Calculator object destroyed\n";
}

int main()
{
    Calculator c;
}