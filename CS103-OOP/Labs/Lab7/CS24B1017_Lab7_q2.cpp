#include <iostream>
#include <vector>

int main()
{
    int m, n;
    std::cout << "Enter size of matrix: ";
    std::cin >> m >> n;
    std::vector<std::vector<int>> matrix;
    std::vector<int> Out;
    std::cout << "Enter matrix: \n";
    for (int i = 0; i < m; i++)
    {
        std::vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int val;
            std::cin >> val;
            temp.push_back(val);
        }
        matrix.push_back(temp);
    }

    std::cout << "Output: ";

    int front{0}, back{n}, top{0}, bottom{m};

    while (front < back && top < bottom)
    {
        for (int j = front; j < back; j++)
        {
            Out.push_back(matrix[top][j]);
        }
        top++;
        for (int j = top; j < bottom; j++)
        {
            Out.push_back(matrix[j][back - 1]);
        }
        back--;
        for (int j = back - 1; j >= front; j--)
        {
            Out.push_back(matrix[bottom - 1][j]);
        }
        bottom--;
        for (int j = bottom - 1; j >= top; j--)
        {
            Out.push_back(matrix[j][front]);
        }
        front++;
    }

    for (size_t i = 0; i < (m * n); i++)
    {
        std::cout << Out[i] << " ";
    }
}
