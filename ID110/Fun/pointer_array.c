#include<stdio.h>

void element(int*,int);

int main()
{
    int i,nums[7] = {1,12,25,75,100,200,400};


    element(nums,7);
    printf("\n");
    for ( i = 0; i < 7; i++)
    {
        printf("%d ",nums[i]);
    }
    
}

void element(int* arr,int n)
{
    int p;
    if(n<=0)
        return;
    p = *(arr + n - 1);
    *(arr + n - 1) = *(arr);
    *arr = p;
    return element(arr+1,n-2);
}