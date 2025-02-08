#include<stdio.h>

void primeFactors(int);

int main()
{
    int a,i,j;
    printf("Enter a number: ");
    scanf("%d",&a);
    printf("Prime factors are: ");
    primeFactors(a);
}

void primeFactors(int a)
{
    int i,j,k;
    
    for ( i = 2; i <= a; i++)
    {       
        if (a%i == 0)
        {
            for ( j = 2,k=0; j < i ; j++)
            {
                if (i%j==0)
                {
                    k++;
                    break;
                } 
            }
            if (k == 0)
            {
                printf("%d ",i);
                primeFactors(a/i);
                break;
            }
        }
    }
}