#include <iostream>
#include <string>
class Calculator
{
private:
    std::string expression;

public:
    Calculator();
    double solver(std::string);
    ~Calculator();
};

Calculator::Calculator()
{
    std::cin >> expression;
    std::cout << "Result: " << solver(expression) << "\n";
}
// Trying to solve using recursion

double Calculator::solver(std::string expr)
{
    double evaluates, num1{0}, num2{0};
    char ch{'+'};
    bool isnum1 = true;
    for (int i = 0; i < expr.length(); i++)
    {
        if (48 <= expr.at(i) && expr.at(i) <= 58 && isnum1)
        {
            num1 *= 10;
            num1 += (static_cast<int>(expr.at(i)) - 48);
            continue;
        }
        else if (48 <= expr.at(i) && expr.at(i) <= 58 && !isnum1)
        {
            num2 *= 10;
            num2 += (static_cast<int>(expr.at(i)) - 48);
            continue;
        }
        else if (expr.at(i) == '+' || expr.at(i) == '-' ||
                 expr.at(i) == '*' || expr.at(i) == '/')
        {
            ch = expr.at(i);
            isnum1 = false;
            continue;
        }

        if (expr.at(i) == '(')
        {
            int j{i}, count{1};
            while (count != 0)
            {
                j++;
                if (expr.at(j) == '(')
                    count++;
                else if(expr.at(j) == ')')
                    count--;
            }
            std::string subexpr = expr.substr(i + 1, j - i - 1);
            if (isnum1)
            {
                num1 = solver(subexpr);
                i = j;
                isnum1 = !isnum1;
                continue;
            }
            num2 = solver(subexpr);
            i = expr.length();
        }
        // if (1 > num1 || num1 > 1000)
        // {
        //     std::cout << "Error: Invalid inputs!\n";
        //     return;
        // }
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
        {
            std::cout << "Error: Invalid operator!\n";
            break;
        }
        // if (1 > num1 || num1 > 1000)
        // {
        //     std::cout << "Error: Invalid inputs!\n";
        //     return;
        // }
    }
    switch (ch)
    {
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':
        if (num2 == 0)
        {
            std::cout << "Error: Division by zero!";
            break;
        }
        return num1 / num2;
        break;
    default:
        break;
    }
    return 0;
}

Calculator::~Calculator()
{
    std::cout << "Calculator object destroyed\n";
}

int main()
{
    std::cout << "Enter expression: ";
    Calculator C;
}