//This program checks for Ramanujan or Taxi-cab numbers
#include<stdio.h>
int main ()
{
    int i,a,b,c,j,r;
    for(i=1;i<=15000;i++)
    {
        r = 1;
        for ( j = 1; j <= 30; j++)
        {
            for (a = 1;a <= 30;a++)
            {
                if (j<a && i == a*a*a+j*j*j)
                {
                    if (r == 2)
                    {
                        printf("%d is a Ramanujan Number as it is the sum of %d^3+%d^3 AND %d^3+%d^3\n",i,j,a,b,c);
                        break;
                    }
                    r++;
                    b = j;
                    c = a;
                }
                
            }  
        }
    }
}