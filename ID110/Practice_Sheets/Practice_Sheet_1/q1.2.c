//   //This program find the factorial of a given number
#include<stdio.h>
int main(){
    int a,b,c,d;
    printf("Enter a Number: ");
    scanf("%d",&a);
    for ( b = 1,c = 1; b <= a; b++)
    {c = c*b;}
    printf("The Factorial of %d = %d\n",a,c);
}