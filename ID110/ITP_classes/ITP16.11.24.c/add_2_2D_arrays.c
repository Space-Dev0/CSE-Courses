#include<stdio.h>

void input(int m,int n,int arr[m][n])
{
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
    int i,j,r1,c1,r2,c2;
    printf("Enter rows and columns of first array: ");
    scanf("%d %d",&r1,&c1);
    int arr1[r1][c1];
    input(r1,c1,arr1);
    printf("Enter rows and columns of first array: ");
    scanf("%d %d",&r2,&c2);
    int arr2[r2][c2];
    input(r2,c2,arr2);
    if (r1 != r2 && c1 != c2)
        printf("Number of Rows and columns are nor equal");
    else
        {
            printf("Sum of the arrays is: \n");
            for ( i = 0; i < r1; i++)
            {
                for ( j = 0; j < c1; j++)
                    printf("%d ",arr1[i][j]+arr2[i][j]);
            printf("\n");
            }
        }
    
}