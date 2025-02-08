#include<stdio.h>

int main()
{
    int n,i,j;
    printf("Enter gate size: ");
    scanf("%d",&n);
    int gate[n][n];
    printf("Enter gates values: ");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&gate[i][j]);
        }
    }
    printf("Enter initial vector: ");
    int initialV[n];
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&initialV[i]);
    }
    int finalV[n];
    int sum;
    for ( i = 0; i < n; i++)
    {
        sum = 0;
        for ( j = 0; j < n; j++)
        {
            sum = sum + gate[i][j]*initialV[j];
        }
        finalV[i] = sum;
    }
    printf("Final vector: ");
    for ( i = 0; i < n; i++)
    {
        printf("%d ",finalV[i]);
    }

    printf("\n");
    
    return 0;
}