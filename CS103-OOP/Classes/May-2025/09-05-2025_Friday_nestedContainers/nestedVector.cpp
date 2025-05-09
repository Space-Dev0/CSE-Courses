#include <iostream>
#include <vector>
int main()
{
    std::vector<std::vector<int>> m1;
    int m1Rows, m1Cols;
    std::cout << "Enter Size of Matrix 1: ";
    std::cin >> m1Rows >> m1Cols;

    std::cout << "Enter data\n";
    for (size_t i = 0; i < m1Rows; i++)
    {
        std::vector<int> temp(m1Cols);

        for (size_t j = 0; j < m1Cols; j++)
            std::cin >> temp[j];

        m1.push_back(temp);
    }

    std::vector<std::vector<int>> m2;
    int m2Rows, m2Cols;
    std::cout << "Enter Size of Matrix 2: ";
    std::cin >> m2Rows >> m2Cols;

    std::cout << "Enter data\n";
    for (size_t i = 0; i < m2Rows; i++)
    {
        std::vector<int> temp(m2Cols);

        for (size_t j = 0; j < m2Cols; j++)
            std::cin >> temp[j];

        m2.push_back(temp);
    }

    if (m1Rows == m2Rows && m2Cols == m1Cols)
    {
        std::cout << "Adding\n";

        for (size_t i = 0; i < m1Rows; i++)
        {
            for (size_t j = 0; j < m2Cols; j++)
            {
                std::cout << m1[i][j] + m2[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
}
