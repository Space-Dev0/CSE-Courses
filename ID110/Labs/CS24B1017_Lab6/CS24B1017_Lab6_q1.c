#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z;
    printf("Enter the depth of array: ");
    scanf("%d", &x);
    printf("Enter the rows of each array: ");
    scanf("%d", &y);
    printf("Enter the columns of each array: ");
    scanf("%d", &z);
    if (x == 0 || y == 0 || z == 0)
    {
        printf("\nArray is empty");
        return 0;
    }
    
    int ***arr = (int ***)malloc(x * sizeof(int *));
    for (int i = 0; i < y; i++)
    {
        *(arr + i) = (int **)malloc(y * sizeof(int *));
        for (int j = 0; j < z; j++)
        {
            *(*(arr + i) + j) = malloc(z * sizeof(int));
        }
    }

    int sum = 0;
    printf("Enter elements of arr: \n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                scanf("%d", *(*(arr + i) + j) + k);
                sum = sum + *(*(*(arr + i) + j) + k);
            }
        }
    }

    int max = *(*(*(arr + 0) + 0) + 0);
    int maxIndex[3] = {0, 0, 0};

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if (max < *(*(*(arr + i) + j) + k))
                {
                    max = *(*(*(arr + i) + j) + k);
                    maxIndex[0] = i;
                    maxIndex[1] = j;
                    maxIndex[2] = k;
                }
            }
        }
    }

    printf("\nSum: %d\n",sum);
    printf("Index: ");
    for (int i = 0; i < 3; i++)
        printf("%d ",maxIndex[i]);
    printf("\nMax element is: %d\n",max);   
    for (int i = 0; i < x; i++)
    {
        printf("slice-%d:\n", i);
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                printf("%d ", *(*(*(arr + i) + j) + k));
            }
            printf("\n");
        }
    }
}