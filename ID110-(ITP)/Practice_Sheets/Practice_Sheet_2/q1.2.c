#include<stdio.h>

void binary(int);

int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    printf("Binary %d = ",x);
    binary(x);
}

void binary(int x)
{
    if(x==0)
        return;
    binary(x/2);
    printf("%d",x%2);
}