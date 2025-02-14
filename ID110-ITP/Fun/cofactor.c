#include <stdio.h>

void cofactor(int(*arr)[3])
{
    int i, j, k = 0, l = 0, temp[2][2],arrCopy[3][3];

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            arrCopy[i][j] = arr[i][j];
        }
        
    }
    
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            for ( int m = 0; m < 3; m++)
            {
                if (m==i)
                    continue;
                
                for ( int n = 0; n < 3; n++)
                {
                    if (n==j)
                        continue;

                    if (l<2)
                    {
                        temp[k][l] = arrCopy[m][n];
                        l++;
                    }
                    else
                    {
                        k++;
                        l = 0;
                        temp[k][l] = arrCopy[m][n];
                        l++;
                    }
                }
                
            }

            if ((i+j)%2  == 0)
            {
                arr[i][j] = temp[1][1]*temp[0][0]-temp[1][0]*temp[0][1];
            }
            else
                arr[i][j] = temp[1][0]*temp[0][1]-temp[1][1]*temp[0][0];
        }
    }
}


int main()
{
    int i, j;
    int arr[3][3];
    printf("Enter elements of matrix :");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    cofactor(arr);

    printf("{\n");
    for (i = 0; i < 3; i++)
    {
        printf("(\t");
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf(")\n");
    }
    printf("}");

    return 0;
}