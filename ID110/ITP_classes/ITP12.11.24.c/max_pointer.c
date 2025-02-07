#include<stdio.h>

int* max(int*,int*);

int main()
{   
    int a,b;
    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);
    printf("Max of a,b is %d\n",*max(&a,&b));
    return 0;
}

int* max(int*a, int*b)
{
    if (*a > *b)
        return a;
    else
        return b;
}