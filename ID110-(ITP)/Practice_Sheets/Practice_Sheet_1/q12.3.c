//This program prints * pyramid
#include<stdio.h>
int main ()
{
    int a,b,c,d,e,f;
    printf("Enter number of rows: ");
    scanf("%d",&a);
    for ( b = 0; b < a; b++)
    {
        for ( d = a-b;d>0;d--)
            printf(" ");
        for ( c = 0; c < 2*b+1; c++)
            printf("*");
        printf("\n");
    }   
}