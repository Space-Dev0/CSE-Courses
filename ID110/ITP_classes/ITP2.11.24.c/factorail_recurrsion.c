#include<stdio.h>

int factorial(int);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("The factorial of the number %d is %d\n",n,factorial(n));
    return 0;
}

int factorial(int a)
{   
    if (a==1)
    {
        return 1;
    }
    return a*factorial(a-1);
}