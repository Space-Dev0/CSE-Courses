#include "sqr.h"

gauss_sqr::gauss_sqr(matrix &M, vector<double> &V) : vec(V), matrix(M)
{
    upperTriangular(vec);
    solution.resize(numRows);
    solver(0);
}

void gauss_sqr::solver(int i)
{
    if (numRows - 1 == i)
    {
        solution[i] = vec[i] / data[i][i];
        return;
    }
    else
    {
        solver(i + 1);
        double sum{0};
        for (int j = numRows - 1; j > i; j--)
            sum += solution[j] * data[i][j];
        solution[i] = (vec[i] - sum) / data[i][i];
    }
}

void gauss_sqr::displayAll()
{
    cout << "\n";
    for (int i = 0; i < numRows / 2; i++)
        cout << "\t";
    cout << "Augmented Matrix\tSolution Vector\n";
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numRows; j++)
        {
            if (data[i][j] < 0)
                cout << "\b";
            cout << data[i][j] << "\t";
        }
        cout << "\b\b |  ";
        if (vec[i] < 0)
            cout << "\b";
        cout << vec[i] << "\t\t";
        if (solution[i] < 0)
            cout << "\b";
        cout << solution[i] << "\n";
    }
    cout << "\n";
}
