/*
 *      Data                                          Function
 *       |                                               |
 *       v                                               v
 * -------------           -------------           -------------
 * |           |<----------|           |<----------|           |
 * | Container |           |  Iterator |           | Algorithms|
 * |           |---------->|           |---------->|           |
 * -------------           -------------           -------------
 *
 */

/* VECTORS
 *
 * include -> #include<vector>
 *
 * Usage
 *               Datatype
 *                  |
 *                  v
 * std::vector <Typename> vectorVarName
 *
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> A;
    if (A.empty())
    {
        std::cout << "A has size zero. \n";
    }
    A.push_back(12);
    A.push_back(-25);
    std::cout << "Size of A: " << A.size() << "\n";
    A.pop_back();
    std::cout << "Size of A: " << A.size() << "\n";
    A.resize(12);
    std::cout << "Size of A: " << A.size() << "\n";
    A.clear();
    std::cout << "Size of A: " << A.size() << "\n";
}
