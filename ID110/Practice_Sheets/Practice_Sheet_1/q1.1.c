//  //This program finds the sum of a digit unti it is reduced to a single digit
#include<stdio.h>
void main(){
    int a,b,c,d;
    printf("Enter a number: ");
    scanf("%d",&a);
    do
    {
        c = 0;
        while (a>0)
        {
            b = a%10;
            a = a/10;
            c = c+b;
        }   
        a = c;
    }while(c>=10);
    printf("%d\n",c);
}