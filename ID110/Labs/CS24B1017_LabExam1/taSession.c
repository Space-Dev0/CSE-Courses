#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    printf("Enter size of array: ");
    int n;
    scanf("%d",&n);
    int* ptr = (int*)malloc(n*sizeof(int));
    int* pt = (int*)calloc(n,sizeof(int));
    printf("Initiial Values: \n");
    for (int i = 0; i < n; i++)
        printf("%d ",ptr[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ",pt[i]);
    printf("Enter the values: ");
    for (int i = 0; i < n; i++)
        scanf("%d",&ptr[i]);
    printf("Your array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ",ptr[i]);
    printf("Enter the values: ");
    for (int i = 0; i < n; i++)
        scanf("%d",&pt[i]);
    printf("Your array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ",pt[i]);
}