#include<stdio.h>

void input(int m,int n,int arr[m][n])
{
    printf("Enter Elements of the array: ");
    int i,j;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}

int main()
{
    int i,j,k,r1,r2,c1,c2,sum;
    printf("Enter rows and columns of first array: ");
    scanf("%d %d",&r1,&c1);
    int arr1[r1][c1];
    input(r1,c1,arr1);
    printf("Enter rows and columns of first array: ");
    scanf("%d %d",&r2,&c2);
    int arr2[r2][c2];
    input(r2,c2,arr2);
    if (c1!=r2)
    {
        printf("Matrix multiplication is not possible");
        return 0;
    }
    else
    {
        int arrResult[r1][c2];
        for ( i = 0; i < r1; i++)
        {
            for ( j = 0; j < c2; j++)
            {
                for ( k = 0,sum =0; k < r2; k++)
                {
                    sum = sum + arr1[i][k]*arr2[k][i]; 
                }
                
                arrResult[i][j] = sum; 
            }
        }
        for ( i = 0; i < r1; i++)
        {
            for ( j = 0; j < c2; j++)
            {
                printf("%d ",arrResult[i][j]);
            }
            printf("\n");
        }
    }
    
}
