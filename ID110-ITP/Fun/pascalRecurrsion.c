#include<stdio.h>

int pascal(int,int);

int main()
{
    int i,a,j,k;
    printf("Enter no. of rows: ");
    scanf("%d",&a);
    for ( i = 0; i < a; i++)
    {
        for ( k = 0; k < a-i ; k++)
            printf(" ");
        for ( j = 0; j < i+1; j++)
            printf("%d ",pascal(i,j));

        printf("\n");
    }
}

int pascal(int r,int c)
{
    if(c==0||c==r)
        return 1;
    return pascal(r-1,c)+pascal(r-1,c-1);
}
