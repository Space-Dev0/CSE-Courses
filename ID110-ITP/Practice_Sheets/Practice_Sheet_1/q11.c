/*This program prints all integers that are not divisible by either 2 or 3 and 
lie between two integers m and n specified by the user*/
#include<stdio.h>
int main ()
{
    int m,n,c=0,d,e;
    printf("Give m: ");
    scanf("%d",&m);
    printf("Give n: ");
    scanf("%d",&n);
    if (n>m)
    {
        n = n+m;
        m = n-m;
        n = n-m;
    }
    while(n<m)
    {
        n++;
        if(0 != n%2 & 0 != n%3)
        {
            printf("%d, ",n);
            c++;
        }
    }
    printf("\nTotal number of integers between %d and %d which are not divisible by 2 && 3 are : %d\n",n,m,c);
}