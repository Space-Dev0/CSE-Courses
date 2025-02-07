//This program calculates sum of the harmonic series
#include<stdio.h>
int main ()
{
int n;
float i,a;
printf("Enter number of terms to be summed: ");
scanf("%d",&n);
for (i = 1; i <= n; i++)
{a = a +1/i;}
printf("= %f\n",a);
}
