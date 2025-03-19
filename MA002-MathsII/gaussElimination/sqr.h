#ifndef SQR_H
#define SQR_H

#include "../matrix.h"

class gauss_sqr : protected matrix
{
private:
    vector<double> vec;
    vector<double> solution;
    void solver(int);

public:
    gauss_sqr(matrix &M, vector<double> &V);
    void displayAll();
};

#endif