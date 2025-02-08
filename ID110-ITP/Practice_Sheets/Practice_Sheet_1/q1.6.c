//  //This program swaps two numbers without using a third variable
#include<stdio.h>
int main ()
{
    int a,b;
    printf("Enter value for variable 'a': ");
    scanf("%d",&a);
    printf("Enter value for variable 'b': ");
    scanf("%d",&b);
    a = a+b;
    b = a-b;
    a = a-b;
    printf("Value for 'a' now is %d\n",a);
    printf("Value for 'b' now is %d\n",b); 
}