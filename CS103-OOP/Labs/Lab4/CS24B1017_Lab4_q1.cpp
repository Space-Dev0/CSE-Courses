#include <iostream>

template <typename T>
T add(T num1, T num2)
{
    return num1 + num2;
}

template <typename T>
T subtract(T num1, T num2)
{
    return num1 - num2;
}

template <typename T>
T multiply(T num1, T num2)
{
    return num1 * num2;
}

template <typename T>
T divide(T num1, T num2)
{
    return num1 / num2;
}

template <typename T>
void inputOp(T num1, T num2)
{
    while (true)
    {
        char op;
        std::cout << "Enter operation(+, -, *, /): ";
        std::cin >> op;
        switch (op)
        {
        case '+':
            std::cout << "Result: " << add(num1, num2) << "\n";
            return;
        case '-':
            std::cout << "Result: " << subtract(num1, num2) << "\n";
            return;
        case '*':
            std::cout << "Result: " << multiply(num1, num2) << "\n";
            return;
        case '/':
            std::cout << "Result: " << divide(num1, num2) << "\n";
            return;
        default:
            std::cout << "err: invalid operation\n";
            continue;
        }
    }
}

template <typename T>
void input(std::string s, T *num1, T *num2)
{
    std::cout << "Enter first " << s << " number: ";
    std::cin >> *num1;
    std::cout << "Enter second " << s << " number: ";
    std::cin >> *num2;

    inputOp(*num1, *num2);
}

int main()
{

    while (true)
    {
        int type;
        std::string ty;
        while (true)
        {
            std::cout << "Enter 1 for int, 2 for float, 3 for double: ";
            std::cin >> type;

            switch (type)
            {
            case 1:
            {
                ty = "integer";
                int num1, num2;
                input(ty, &num1, &num2);
                break;
            }
            case 2:
            {
                ty = "float";
                float num1, num2;
                input(ty, &num1, &num2);
                break;
            }
            case 3:
            {
                ty = "double";
                double num1, num2;
                input(ty, &num1, &num2);
                break;
            }
            default:
            {
                std::cout << "err: Value should be between 1,2 or 3\n";
                continue;
                break;
            }
            }
            break;
        }
        int check;
        while (true)
        {
            std::cout << "Enter 1 to continue, or 0 to exit: ";
            std::cin >> check;

            if (check == 0)
            {
                std::cout << "“Calculator exited. Goodbye!”\n";
                exit(0);
            }
            else if (check == 1)
                break;
            else
            {
                std::cout << "err: Value should be 0 or 1\n";
            }
        }
    }
}