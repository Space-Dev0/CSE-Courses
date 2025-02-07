#include <stdio.h>
#include <stdlib.h>

void printarr(int *dimentions, int n, int *arr, int totalSize, int pointer);

int main()
{
    int i, j, k, n;
    printf("Enter number of dimentions: ");
    scanf("%d", n);
    int dimentions[n];
    printf("Enter the sizes of dimentions: ");
    for (i = 0; i < n; i++)
        scanf("%d", &dimentions[i]);
    int totalSize = 1;
    for (i = 0; i < n; i++)
    {
        totalSize = totalSize * dimentions[i];
    }
    int *arr = (int *)malloc(totalSize * sizeof(int));
    for (i = 0; i < totalSize; i++)
    {
        scanf("%d", arr + i);
    }
    // int *temp = (int *)calloc(n, sizeof(int));
    // k = 0;
    // int l = 0;
    // for (i = 0; i < n; i++)
    // {
    //     for (j = n - 1; j > 0; j--)
    //     {
    //         if (temp[j] == 0)
    //         {
    //             printf("[");
    //         }
    //     }
    //     while (temp[n - 1] * temp[n - 2] != dimentions[n - 2] * temp[n - 1])
    //     {
    //         printf("%d ", arr[k]);
    //         k++;
    //         if (temp[n - 1] == dimentions[n - 1])
    //         {
    //             temp[n - 2]++;
    //             continue;
    //         }
    //         temp[n - 1]++;
    //     }
    //     temp[n - 3] == 0;
    // }
}

void printarr(int *dimentions, int n, int *arr, int totalSize, int pointer)
{
    printf("[");
    if (n <= 2)
    {
        while (pointer < dimentions[n - 1] * dimentions[n - 2])
        {
            printf("%d ",arr[pointer]);
            pointer++;
        }
    }
    
    printf("]");
}