#include<stdio.h>

int power(int,int);

int main()
{
    int x,y;
    printf("Enter base: ");
    scanf("%d",&x);
    printf("Enter power: ");
    scanf("%d",&y);
    printf("%d^%d = %d\n",x,y,power(x,y));
}

int power(int a,int b)
{
    if (b==1) return a;
    else
        return a*power(a,b-1);
}
