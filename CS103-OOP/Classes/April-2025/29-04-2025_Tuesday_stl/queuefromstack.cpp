#include <iostream>
#include <stack>

int main()
{
    std::stack<int> s1, s2;

    while (1)
    {
        int i;
        std::cout << "Enter 1 for pushing 0 for popping: ";
        std::cin >> i;
        if (i == 1)
        {
            int data;
            std::cout << "Enter data: ";
            std::cin >> data;
            s1.push(data);
        }
        else
        {
            size_t size1 = s1.size();
            for (size_t i = 0; i < size1; i++)
            {
                s2.push(s1.top());
                s1.pop();
            }
            std::cout << "Data: " << s2.top() << "\n";
            s2.pop();
            size_t size2 = s2.size();
            for (int i = 0; i < size2; i++)
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
}