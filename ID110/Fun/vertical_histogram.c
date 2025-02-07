#include<stdio.h>
int main()
{
    int a,b,c,i,d;
    printf("Enter the size of array: ");
    scanf("%d",&a);
    int arr[a];
    for ( i = 0; i < a; i++)
        scanf("%d",&arr[i]);
    for ( i = 0; i < a; i++)
        if (arr[i]>arr[c])
            c = i;  
    d = arr[c];
    for ( i = 0; i < arr[c]; i++)
    {
        for ( b = 0; b < a; b++)
        {
            if (arr[b]-d>=0)
                printf("  *  ");
            else
                printf("     ");
        }   
        d--;
        printf("\n");
    }
    for ( i = 0; i < a; i++)
        printf("  %d  ",arr[i]);
    printf("\n");
}