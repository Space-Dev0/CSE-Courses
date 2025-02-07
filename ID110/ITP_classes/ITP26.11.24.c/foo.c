#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* arr,i=0;
    arr = (int*)malloc(sizeof(int)*1);
    int*arr1 = arr;
    while (arr1 == arr)
    {
        printf("\nEnter a number at the %d index: ",i   );
        arr[i] = i+1;
        i++;
        arr = realloc(arr,(i+1)*sizeof(int));
        printf("address of array: %p\n",arr);

    }
    
}