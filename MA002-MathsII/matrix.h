#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

class matrix
{
private:
    void init(int numRows, int numCols);

protected:
    vector<vector<double>> data;
    int numRows{0};
    int numCols{0};
    bool squarematrix{false};
    bool error{false};
    void upperTriangular(vector<double> &vec);
    void upperTriangular();

public:
    matrix(int n);
    matrix(int n, int m);
    matrix();
    matrix operator+(matrix &B);
    matrix operator-(matrix &B);
    matrix operator*(matrix &B);
    matrix operator*(int s);
    matrix operator/(int s);
    void display();
    void input();
};

#endif