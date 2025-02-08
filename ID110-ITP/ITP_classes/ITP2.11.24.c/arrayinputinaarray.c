#include<stdio.h>

int max(int[],int);

int main()
{
    int a,i;
    printf("Enter the size of array: ");
    scanf("%d",&a);
    int arr[a];
    for ( i = 0; i < a; i++)
        scanf("%d",&arr[i]);
    printf("Max of array is %d\n",max(arr,a));
}

int max(int arr[],int a)
{
    int i,b;
    for ( i = 0,b = arr[0]; i < a; i++)
    {
        if (b<arr[i])
            b = arr[i];
    }
    return b;
}