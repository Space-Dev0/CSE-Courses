//  //This program checks if entered year is leap year
#include<stdio.h>
int main ()
{
    int a,b,c,d;
    printf("Enter the year: ");
    scanf("%d",&a);
    if (a%400 == 0 || (a%4 == 0 & a%100 != 0))
    printf("It is a Leap Year\n");
    else printf("It is not a Leap Year\n");

}