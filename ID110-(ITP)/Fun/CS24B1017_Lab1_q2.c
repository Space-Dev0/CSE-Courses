#include<stdio.h>

int LCM(int, int);
int GCD(int, int);

int main()
{
    int m,n;
    printf("Enter first number: ");
    scanf("%d",&m);
    printf("Enter second number: ");
    scanf("%d",&n);
    printf("The LCM of the two numbers is: %d\n",LCM(m,n));
    printf("The GCD of the two numbers is: %d\n",GCD(m,n));
    return 0;
}

int LCM(int m,int n)
{
    int i;  
    if (n <= 1 || m <= 1)
        return m*n;
        /*This is the base case here if one of the number is 1 
        it will return the number itself*/
    else
    {   for ( i = m; i >0 ; i--)
        {
            if (i==1)
            {
                m = m*n;
                n = 1;
                break;
            }
            else if (n%i==0 && m%i == 0)
            {
                m = m/i;
                n = n/i;
                break;
            }
            
        }
        return i * LCM(m,n);
    }    
}

int GCD(int m, int n)
{
    int i;
    if (n <= 1 || m <= 1)
        return 1;
        /*This is the base case here if one of the number is 1 
        it will return 1*/
    else
    {   for ( i = m; i >0 ; i--)
        {
            if (i==1)
            {
                m = m*n;
                n = 1;
                break;
            }
            else if (n%i==0 && m%i == 0)
            {
                m = m/i;
                n = n/i;
                break;
            }
            
        }
        return i * GCD(m,n);
    }    
    
}
