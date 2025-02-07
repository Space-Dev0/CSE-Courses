//This program prints * triangle upside down
#include<stdio.h>
int main ()
{
    int a,b,c,d;
    printf("Enter number of rows: ");
    scanf("%d",&a);
    for ( b = a; b > 0 ; b--)
    {
        for (d = a-b; d>0 ;d--)
            printf(" ");
        for ( c = b; c >0; c--)
            printf("*");
        printf("\n");
    }
}
