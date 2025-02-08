#include<stdio.h>
#include<math.h>

int seriesSum(int);

int main()
{
    int a,b,c;
    printf("Enter a number: ");
    scanf("%d",&a);
    printf("Sum of Series: %d",seriesSum(a));
}

int seriesSum(int n)
{
    if (n==0)
        return 3;
    else
        return (n+1)*(n+1)*(n+1)+2*(n+1)+ seriesSum(n-1);
}