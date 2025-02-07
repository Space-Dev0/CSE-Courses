//  //This program compute a^b where a is the base and b is the exponent
#include<stdio.h>
int main ()
{
    int b,d,e;
    float a,c;
    printf("Enter base value: ");
    scanf("%f",&a);
    printf("Enter exponent: ");
    scanf("%d",&b);
    d = b<0?-b:b;
    for(c=1;d>0;d--)
    {c=c*a;}
    printf("%f^%d = %f",a,b,b<0?1/c:c);
}