#include<stdio.h>

int fib(int);
int fibSum(int);

int main()
{
    int a;
    printf("Enter till sum of fibonnaci is required");
    scanf("%d",&a);
    printf("Sum is: %d",fibSum(a));
}

int fib(int n)
{
    if(n==0)
        return 0;//base case if n is 0 returning 1
    else if(n==1)
        return 1;// base case if n is 1 returning 2
    else 
        return fib(n-1)+fib(n-2);
}

int fibSum(int m)
{
    if (m == 1)
        return 0;
    else
    {
        return fibSum(m-1)+fib(m-1);
    }
}