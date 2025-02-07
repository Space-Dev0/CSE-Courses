#include<stdio.h>
void main()
{
    int i; 
    int a[9];
    for ( i = 0; i < 10; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&a[i]);
    }
    for ( i = 0; i < 10; i++)
        printf("%d ",a[i]);
    
}