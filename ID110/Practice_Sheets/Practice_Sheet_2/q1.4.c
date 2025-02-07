#include<stdio.h>

int binomialCoefficient(int,int);

int main()
{
    int n,r;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter r: ");
    scanf("%d",&r);
    printf("C(%d,%d) = %d\n",n,r,binomialCoefficient(n,r));
}

int binomialCoefficient(int n,int r)
{
    if(n==r||r==0)
        return 1;
    else
        return binomialCoefficient(n-1,r)+binomialCoefficient(n-1,r-1);
}