#include<stdio.h>

int main()
{
    int i,a = 3,j = 2,k =5;
    int* arr[3];
    arr[0] = &a;
    arr[1] = &j;
    arr[2] = &k;
    *arr[0] = 5; 
    for ( i = 0; i < 3; i++)
    {
        printf("%p  ",arr[i]);
    }
    printf("\n");
    for ( i = 0; i < 3; i++)
    {
        printf("%d  ",*arr[i]);
    }
    
}