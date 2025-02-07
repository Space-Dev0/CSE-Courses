#include<stdio.h>

int sum()
{
    int a;
    printf("Enter a number: ");
    scanf("%d",&a);
    if(a==0)
        return 0;
    else
        return sum()+a;
}

int main()
{
    printf("The sum is %d",sum());
}