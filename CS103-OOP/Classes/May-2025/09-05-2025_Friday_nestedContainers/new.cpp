#include <iostream>

int main()
{
    int **x = new int *[3];
    for (size_t i = 0; i < 3; i++)
    {
        x[i] = new int[3]{2, 2, 2};
    }

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cout << x[i][j] << " ";
        }
        std::cout << "\n";
    }
}