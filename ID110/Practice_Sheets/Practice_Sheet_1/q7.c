//This program gives all the pythagorean triplets till 30
#include<stdio.h>
int main ()
{
    int m,n,i;
    for( n = 1; n<=30; n++)
    {
        for ( m = 1; m <= 30; m++)
        {
            for ( i = 1; i <= 30; i++)
            {
                if (i<m && i*i+m*m == n*n)
                {   
                    printf("%d, %d, %d\n",i,m,n);
                }   
            }   
        }
    }   
}