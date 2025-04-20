#include "matrix.h"

void matrix::init(int numRows, int numCols)
{
    for (int i = 0; i < numRows; i++)
    {
        vector<double> temp(numCols);
        data.push_back(temp);
    }
}

matrix::matrix(int n) : numRows(n), numCols(n)
{
    init(n, n);
    squarematrix = true;
}

matrix::matrix(int n, int m) : numRows(numCols), numCols(m)
{
    init(n, m);
    squarematrix = false;
}

matrix::matrix()
{
}
// matrix(matrix &obj) : numRows(obj.numRows),
//                       numCols(obj.numCols), squarematrix(obj.squarematrix)
// {
//     for (int i = 0; i < numRows; i++)
//     {
//         vector<double> temp(numCols);
//         for (int j = 0; j < numCols; j++)
//             temp[j] = obj.data[i][j];
//         data.push_back(temp);
//     }
//     squarematrix = false;
// }

matrix matrix::operator+(matrix &B)
{
    matrix temp(numRows, numCols);
    if (B.numCols != numCols || B.numRows != numRows)
    {
        std::cout << "Error: Matrices must have the same dimensions for addition!\n";
        temp.error = true;
        return temp;
    }
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
            temp.data[i][j] = data[i][j] + B.data[i][j];
    }
    return temp;
}

matrix matrix::operator-(matrix &B)
{
    matrix temp(numRows, numCols);
    if (B.numCols != numCols || B.numRows != numRows)
    {
        std::cout << "Error: Matrices must have the same dimensions for subtraction!\n";
        temp.error = true;
        return temp;
    }
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
            temp.data[i][j] = data[i][j] - B.data[i][j];
    }
    return temp;
}

matrix matrix::operator*(matrix &B)
{
    matrix temp(numRows, B.numCols);
    if (B.numRows != numCols)
    {
        std::cout << "Error: matrix B must have the same number of numRows as columns in A !\n";
        temp.error = true;
        return temp;
    }
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < B.numCols; j++)
        {
            int temp1 = 0;
            for (int k = 0; k < numCols; k++)
            {
                temp1 += data[i][k] * B.data[k][j];
            }
            temp.data[i][j] = temp1;
        }
    }
    return temp;
}
matrix matrix::operator*(int s)
{
    matrix temp(numRows, numCols);
    if (s == 0)
    {
        std::cout << "Error: Division by zero!\n";
        temp.error = true;
        return temp;
    }
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
            temp.data[i][j] = data[i][j] * s;
    }
    return temp;
}
matrix matrix::operator/(int s)
{
    matrix temp(numRows, numCols);
    if (s == 0)
    {
        std::cout << "Error: Division by zero!\n";
        temp.error = true;
        return temp;
    }
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
            temp.data[i][j] = data[i][j] / s;
    }
    return temp;
}

void matrix::display()
{
    cout << "\n";
    for (int i = 0; i < numRows; i++)
    {
        cout << " ";
        for (int j = 0; j < numCols; j++)
        {
            if (data[i][j] < 0)
                cout << "\b";
            cout << data[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void matrix::upperTriangular(vector<double> &vec)
{
    if (!squarematrix)
    {
        std::cerr << "err: Matrix not square\n";
        return;
    }
    else if (vec.size() != numRows)
    {
        std::cerr << "err: vector size not equal\n";
        return;
    }
    for (int i = 0; i < numRows - 1; i++)
    {
        for (int k = i + 1; k < numRows; k++)
        {
            double multiplier = (data[k][i] / data[i][i]);
            for (int j = 0; j < numRows; j++)
                data[k][j] -= multiplier * data[i][j];
            vec[k] -= multiplier * vec[i];
        }
    }
}

void matrix::input()
{
    std::cout << "Enter elements: \n";
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            std::cin >> data[i][j];
        }
    }
}

void matrix::upperTriangular()
{
    if (!squarematrix)
    {
        std::cerr << "err: Matrix not square\n";
        return;
    }

    for (int i = 0; i < numRows - 1; i++)
    {
        for (int k = i + 1; k < numRows; k++)
        {
            double multiplier = (data[k][i] / data[i][i]);
            for (int j = 0; j < numRows; j++)
                data[k][j] -= multiplier * data[i][j];
        }
    }
}

void matrix::lowerTriangular(vector<double> &vec)
{
    if (!squarematrix)
    {
        std::cerr << "err: Matrix not square\n";
        return;
    }
    else if (vec.size() != numRows)
    {
        std::cerr << "err: vector size not equal\n";
        return;
    }
    for (int i = 0; i < numRows - 1; i++)
    {
        for (int k = i + 1; k < numRows; k++)
        {
            double multiplier = (data[k][i] / data[i][i]);
            for (int j = 0; j < numRows; j++)
                data[k][j] -= multiplier * data[i][j];
            vec[k] -= multiplier * vec[i];
        }
    }
}