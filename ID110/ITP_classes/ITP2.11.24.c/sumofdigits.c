#include<stdio.h>

int* bubble (int[],int);

int main()
{
    int i, a;
    printf("Enter the size of array: ");
    scanf("%d",&a);
    int arr[a];
    for ( i = 0; i < a; i++)
        scanf("%d",&arr[i]);

    for (int  i = 0; i < a; i++)
    {
         printf("%d " , bubble(arr,a)[i]);
    }

}

int* bubble(int arr[],int a)
{
    int i,d;
    while (1)
    {
        for ( i = 1,d = 0; i < a; i++)
        {
            if (arr[i]<arr[i-1])
            {
                arr[i] = arr[i]+arr[i-1];
                arr[i-1] = arr[i]-arr[i-1];
                arr[i] = arr[i]-arr[i-1];
                d++;
            }
        }
        if (d==0) break;     
    }
    return arr;
}