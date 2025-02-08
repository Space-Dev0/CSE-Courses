#include<stdio.h>

int sum(int*,int);

int main()
{
    int s,i;
    printf("Enter the size of array: ");
    scanf("%d",&s);
    int arr[s];
    for ( i = 0; i < s; i++)
        scanf("%d",&arr[i]);
    printf("Sum of elements of array is: %d",sum(arr,s));
}

int sum(int* arr,int a)
{
    if(a==1) return *arr;
    else
        return *arr + sum(arr+1,a-1);
}