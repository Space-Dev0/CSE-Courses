#include "sqr.h"

int main()
{
    matrix A(3);
    A.input();
    vector<double> V(3);
    cout << "Enter B: ";
    for (int i = 0; i < 3; i++)
        cin >> V[i];
    gauss_sqr G(A, V);
    G.displayAll();
}