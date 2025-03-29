#include <iostream>

template <typename T>
class Calculate
{
private:
    T val1;
    T val2;
    char op;

public:
    Calculate()
    {
        std::cout << "Enter expression: ";
        std::cin >> val1 >> op >> val2;
    }
    Calculate(T num1, char c, T num2) : val1(num1), val2(num2), op(c) {}
    void display()
    {

        std::cout << "Evaluates to: ";
        switch (op)
        {
        case '+':
            std::cout << val1 + val2 << "\n";
            break;

        case '-':
            std::cout << val1 - val2 << "\n";
            break;

        case '*':
            std::cout << val1 * val2 << "\n";
            break;

        case '/':
            std::cout << val1 / val2 << "\n";
            break;
        default:
            break;
        }
    }
};

int main()
{
    Calculate C1(12, '+', 3);
    C1.display();
    Calculate C2(12.3, '-', 3.4);
    C2.display();
    Calculate C3('c', '*', 'd');
    C3.display();

    Calculate<int> C;
    C.display();
}