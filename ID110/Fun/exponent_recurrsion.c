#include<stdio.h>

double power(float,int);

int main ()
{
    int b;
    float a;
    printf("Enter a number: ");
    scanf("%f",&a);
    printf("Enter power: ");
    scanf("%d",&b);
    printf("a^b = %lf",power(a,b));
}

double power(float a,int b)
{
    if (b == 0)
        return 1;
    
    else
        return a*power(a,b-1); 
}