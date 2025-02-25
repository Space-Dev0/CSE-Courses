#include <iostream>
#include <string_view>

class Calculator
{
private:
    double solver(std::string_view);
    double evaluate(double, double, char);
    std::string_view subexpression(std::string_view, int *);
    bool err{0};

public:
    Calculator();
    Calculator(std::string_view expression);
    ~Calculator();
};

Calculator::Calculator()
{
    std::cout << "Enter expression: ";
    std::string expression;
    std::cin >> expression;
    double result = solver(expression);
    if (err)
        return;
    std::cout << "Result: " << result << "\n";
}

Calculator::Calculator(std::string_view expression)
{
    double result = solver(expression);
    if (err)
        return;
    std::cout << "Result: " << result << "\n";
}

std::string_view Calculator::subexpression(std::string_view expr, int *i)
{
    int j{*i}, count{1};
    while (count != 0)
    {
        (*i)++;
        if (*i >= expr.length())
        {
            std::cout << "Error: Mismatched parentheses!\n";
            err = true;
            return "\0";
        }
        if (expr.at(*i) == '(')
            count++;
        else if (expr.at(*i) == ')')
            count--;
    }
    return expr.substr(j + 1, *i - j - 1);
}

double Calculator::evaluate(double num1, double num2, char ch)
{
    switch (ch)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 == 0)
        {
            std::cout << "Error: Division by zero!\n";
            err = true;
            break;
        }
        return num1 / num2;
    default:
        std::cout << "Error: Invalid operator!\n";
        err = true;
        break;
    }
    return 0;
}

// Trying to solve using recursion

double Calculator::solver(std::string_view expr)
{
    double evaluates, num1{0}, num2{0};
    char ch{'+'};
    bool isnum1 = true;
    for (int i = 0; i < expr.length(); i++)
    {
        if (48 <= expr.at(i) && expr.at(i) <= 58)
        {
            int num = isnum1 ? num1 : num2;
            num *= 10;
            num += (static_cast<int>(expr.at(i)) - 48);
            isnum1 ? num1 = num : num2 = num;
            continue;
        }
        else if (expr.at(i) == '+' || expr.at(i) == '-' || expr.at(i) == '*' || expr.at(i) == '/')
        {
            if (!isnum1)
            {
                num1 = evaluate(num1, num2, ch);
                num2 = 0;
            }
            ch = expr.at(i);
            isnum1 = false;
            continue;
        }
        if (expr.at(i) == '(')
        {
            std::string_view subexpr{subexpression(expr, &i)};
            if (isnum1)
            {
                num1 = solver(subexpr);
                isnum1 = !isnum1;
                continue;
            }
            num2 = solver(subexpr);
        }
    }
    return evaluate(num1, num2, ch);
}

Calculator::~Calculator()
{
    std::cout << "Calculator object destroyed\n";
}

int main()
{
    Calculator C;
}