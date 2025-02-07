#include <stdio.h>

void inverseMatrix(float(*matrix)[3]);
int cofactor(float(*)[3],int,int);

int main()
{
    int i, j;
    float matrix1[3][3];
    printf("Enter elements of Matrix : ");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
                scanf("%f", &matrix1[i][j]);
        }
    }

    inverseMatrix(matrix1);

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%.2f ",matrix1[i][j]);
        }
        printf("\n");
    }
}

void inverseMatrix(float(*matrix)[3])
{
    int i,j;
    float inverseMatrix[3][3],det;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            inverseMatrix[j][i] = cofactor(matrix,i,j);
        }
    }

    det = matrix[0][0]*cofactor(matrix,0,0)+matrix[0][1]*cofactor(matrix,0,1)+matrix[0][2]*cofactor(matrix,0,2);

    if(det==0)
    {
        printf("\n## Matrix not invertible ##\n");
        return;
    }

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            matrix[i][j] = (inverseMatrix[i][j])/(det);
        }
    }
    return;
}

int cofactor(float (*matrix)[3],int r,int c)
{
    int temp[2][2];
    int i,j,k =0 ,l = 0;
    for ( i = 0; i < 3; i++)
    {
        if (i == r)
            continue;
        for ( j = 0; j < 3; j++)
        {
            if(j == c) continue;
            if(l<2)
            {
                temp[k][l] = matrix[i][j];
                l++;
            }
            else
            {
                l = 0;
                k++;
                temp[k][l] = matrix[i][j];
                l++;
            }
        }
    }

    if((r+c)%2 == 0)
        return (temp[0][0]*temp[1][1]-temp[0][1]*temp[1][0]); 
    else
        return (temp[0][1]*temp[1][0]-temp[0][0]*temp[1][1]);
}

