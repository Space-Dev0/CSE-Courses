//This program prints * triangle
#include<stdio.h>
int main ()
{
    int a,b,c,d,e,f;
    printf("Enter number of rows: ");
    scanf("%d",&a);
    for ( b = 1; b <= a; b++)
    {
        for ( c = 0; c < b; c++)
            printf("*");
        printf("\n");
    }
}