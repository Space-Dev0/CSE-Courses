#include<stdio.h>

void swap(int*,int*);

int main()
{
    int x,y;
    printf("Enter x: ");
    scanf("%d",&x);
    printf("Enter y: ");
    scanf("%d",&y);
    printf("The adress of x and uy are: %u %u", &x,&y);
    swap(&x,423);
    printf("x is: %d\n",x);
    printf("y is: %d\n",y);
}

void swap(int* a,int* b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}