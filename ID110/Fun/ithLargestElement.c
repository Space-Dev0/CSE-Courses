#include <stdio.h>

int ithLargest(int, int *, int);

int main()
{
    int i, a, j;
    printf("Enter size of array: ");
    scanf("%d", &a);
    printf("Enter the elements of array: ");
    int arr[a];
    for (i = 0; i < a; i++)
        scanf("%d", &arr[i]);
    printf("Enter i: ");
    scanf("%d", &j);
    printf("\n%d largest element is: %d\n", j, ithLargest(a, arr, j));
}

int ithLargest(int a, int *arr, int j)
{
    int i, k, d, temp;
    while (1)
    {
        for (k = 1, d = 0; k < a; k++)
        {
            if (arr[k - 1] > arr[k])
            {
                temp = arr[k - 1];
                arr[k - 1] = arr[k];
                arr[k] = temp;
                d++;
            }
        }
        if (d == 0)
            break;
    }
    
    for (i = 1; i < a; i++)
    {
        if (arr[i - 1] == arr[i])
        {
            for (k = i; k < a; k++)
                arr[k - 1] = arr[k];
            a--;
            i--;
        }
    }
    
    return j > a ? arr[a - 1] : arr[a - j];
}