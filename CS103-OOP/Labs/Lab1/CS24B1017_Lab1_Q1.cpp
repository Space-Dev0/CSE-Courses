#include <iostream>

class Matrix
{
public:
    int rows;
    int cols;
    int **matrix = NULL;
    bool error = false;

    Matrix(int row, int col)
    {
        rows = row;
        cols = col;

        matrix = (int **)malloc(rows * sizeof(int *));
        for (int i = 0; i < rows; i++)
            matrix[i] = (int *)calloc(cols, sizeof(int));
    }

    void input()
    {
        std::cout << "Enter elements: \n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cin >> matrix[i][j];
            }
        }
    }

    Matrix operator+(Matrix &B)
    {
        Matrix temp(rows, cols);
        if (B.cols != cols || B.rows != rows)
        {
            std::cout << "Error: Matrices must have the same dimensions for addition!\n";
            temp.error = true;
            return temp;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                temp.matrix[i][j] = matrix[i][j] + B.matrix[i][j];
        }
        return temp;
    }

    Matrix operator-(Matrix &B)
    {
        Matrix temp(rows, cols);
        if (B.cols != cols || B.rows != rows)
        {
            std::cout << "Error: Matrices must have the same dimensions for subtraction!\n";
            temp.error = true;
            return temp;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                temp.matrix[i][j] = matrix[i][j] - B.matrix[i][j];
        }
        return temp;
    }

    Matrix operator*(Matrix &B)
    {
        Matrix temp(rows, B.cols);
        if (B.rows != cols)
        {
            std::cout << "Error: Matrix B must have the same number of rows as columns in A !\n";
            temp.error = true;
            return temp;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < B.cols; j++)
            {
                int temp1 = 0;
                for (int k = 0; k < cols; k++)
                {
                    temp1 += matrix[i][k] * B.matrix[k][j];
                }
                temp.matrix[i][j] = temp1;
            }
        }
        return temp;
    }
    Matrix operator/(int s)
    {
        Matrix temp(rows, cols);
        if (s == 0)
        {
            std::cout << "Error: Division by zero!\n";
            temp.error = true;
            return temp;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                temp.matrix[i][j] = matrix[i][j] / s;
        }
        return temp;
    }
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
            free(matrix[i]);
        free(matrix);
    }
};

void printMatrix(Matrix &obj)
{
    for (int i = 0; i < obj.rows; i++)
    {
        for (int j = 0; j < obj.cols; j++)
        {
            std::cout << obj.matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    int rowsA = 0, rowsB = 0, colB = 0, colA = 0, scalar = 0;
    std::cout << "Enter rows and columns for Matrix A: ";
    std::cin >> rowsA >> colA;
    Matrix A(rowsA, colA);
    A.input();
    std::cout << "Enter rows and columns for Matrix B: ";
    std::cin >> rowsB >> colB;
    Matrix B(rowsB, colB);
    B.input();

    std::cout << "Enter scalar value: ";
    std::cin >> scalar;

    std::cout << "\nMatrix A + B: \n";
    Matrix C = A + B;
    if (!C.error)
        printMatrix(C);

    std::cout << "\nMatrix A - B: \n";
    Matrix D = A - B;
    if (!D.error)
        printMatrix(D);

    std::cout << "\nMatrix A * B: \n";
    Matrix E = A * B;
    if (!E.error)
        printMatrix(E);

    std::cout << "\nMatrix A/s: \n";
    Matrix F = A / scalar;
    if (!F.error)
        printMatrix(F);
}