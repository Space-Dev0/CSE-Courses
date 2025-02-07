#include<stdio.h>

void rotateRight(int* arr, int size, int k);

int main()
{
    int i,a,k;

    printf("Enter size of array: ");
    scanf("%d",&a);

    int arr[a];

    //Inputing array
    printf("Enter elements of array: ");
    for ( i = 0; i < a; i++)
        scanf("%d",arr+i);
    
    printf("Enter Rotation factor: ");
    scanf("%d",&k);
    
    rotateRight(arr,a,k);

    //Printing array
    for ( i = 0; i < a; i++)
        printf("%d ",*(arr+i));
}

void rotateRight(int* arr, int size, int k)
{
    if(k == 0)return;  
    int i,temp;
    
    //swaping ith element with last element n-1 times causing 1 rotation
    for ( i = 0; i < size-1; i++)
    {
        temp = *(arr+i);
        *(arr+i) = *(arr+size-1);
        *(arr+size-1) = temp;
    }

    //recurrsively calling function until k == 0 or all rotations are done
    return rotateRight(arr,size,k-1);
}
