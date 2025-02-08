#include<stdio.h>

int fib(int);

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d",&a);
    return fib(a);
}

int fib(int a)
{
    if(a==1)
        return 1;
    if(a==0)
        return 0;
    
    fib(a)=fib(a-1)+fib(a-2);
}