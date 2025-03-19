#include "sqr.h"

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;

    matrix A(size);
    A.input();

    vector<double> V(size);
    cout << "Enter B vector: ";
    for (int i = 0; i < size; i++)
        cin >> V[i];

    gauss_sqr G(A, V);
    G.displayAll();
}