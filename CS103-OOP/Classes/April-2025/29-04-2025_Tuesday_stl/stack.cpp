#include <iostream>
#include <stack>

int main()
{
    std::stack<int> S;
    S.push(12);
    S.push(13);
    S.push(134);
    std::cout << S.top() << "\n";
    S.pop();
    std::cout << S.top() << "\n";
    S.pop();
    std::cout << S.top() << "\n";
}
