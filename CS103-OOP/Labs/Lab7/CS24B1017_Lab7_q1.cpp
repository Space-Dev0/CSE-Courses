#include <iostream>
#include <stack>

class MinStack
{
private:
    std::stack<int> ourStack;
    std::stack<int> min;

public:
    MinStack()
    {
        std::cout << "Stack initalized!\n";
    }
    void push(int val)
    {
        if (min.empty())
            min.push(val);

        else if (val < min.top())
            min.push(val);

        ourStack.push(val);
    }
    void pop()
    {
        if (ourStack.top() == min.top())
            min.pop();

        ourStack.pop();
    }
    int top()
    {
        return ourStack.top();
    }
    int getMin()
    {
        return min.top();
    }
};

int main()
{
    MinStack minS;
    while (1)
    {
        std::string op;
        std::cout << "push _n_    "
                  << "pop    "
                  << "top    "
                  << "getMin\n"
                  << "Enter: ";
        std::cin >> op;

        if (op == "push")
        {
            int val;
            std::cin >> val;
            minS.push(val);
            std::cout << "NULL\n";
        }
        else if (op == "pop")
        {
            minS.pop();
            std::cout << "NULL\n";
        }
        else if (op == "top")
        {
            std::cout << "Top: " << minS.top() << "\n";
            std::cout << "NULL\n";
        }
        else if (op == "getMin")
        {
            std::cout << "Min: " << minS.getMin() << "\n";
            std::cout << "NULL\n";
        }
        else
        {
            std::cout << "Wrong command, retry\n";
            continue;
        }
    }
}