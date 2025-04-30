#include <iostream>
#include <list>

int main()
{
    std::list<int> L;
    while (1)
    {
        int c;
        std::cout << "Enter 1 to add to queue 0"
                  << " to remove from queue any other to exit: ";
        if (std::cin >> c)
        {
            switch (c)
            {
            case 1:
                int d;
                std::cout << "Enter element to add: ";
                std::cin >> d;
                L.push_back(d);
                continue;
            case 0:
                std::cout << "Data: " << L.front() << "\n";
                L.pop_front();
                continue;
            default:
                break;
            }
        }
        break;
    }
    std::cout << "Exiting...\n";
}
