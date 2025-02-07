//This program is calculating electricity bills for slab based pricing
#include<stdio.h>
int main ()
{
    int a,b=0,c,d;
    printf("Enter units of Electricity used: ");
    scanf("%d",&a);
    if (a>50)
    {
        if (a>300)
        {
            b = b+(a-300)*2.5;
            a = 300;
        }
        if (a>150)
        {
            b = b+(a-150)*1.5;
            a = 150;
        }
        if (a>50)
        {
            b = b+(a-50)*1;
            a = 50;
        }
    }
    printf("Electricity Bill = %dRs.\n",b);
}