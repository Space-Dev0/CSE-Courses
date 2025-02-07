#include<stdio.h>

int main()
{
    int m,n;
    printf("Enter the number of rows: ");
    scanf("%d",&m);
    printf("Enter the number of columns: ");
    scanf("%d",&n);
    int i,j,arr[m][n];
    printf("Enter values of array: ");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%p ",&arr[i][j]);
        }
        printf("\n");
    }
    
}