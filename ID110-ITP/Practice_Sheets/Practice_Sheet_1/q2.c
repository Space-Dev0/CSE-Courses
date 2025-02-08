//  //This program checks for Armstrong number
#include<stdio.h>
int main ()
{
    int a,b,c,d;
    printf("Enter a number: ");
    scanf("%d",&d);
    a = d;
    for ( c = 0; a > 0; a = a/10)
    {
        b = a%10;
        c = c+b*b*b;
    }
    printf(c==d?"1\n":"0\n");
}