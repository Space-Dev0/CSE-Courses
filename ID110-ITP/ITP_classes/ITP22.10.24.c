#include<stdio.h>
#include<stdlib.h>
int main ()
{
    //This program prints the max and min of enterd values using array
    // int a[4],i,b,c;
    // i = 0;
    // printf("Enter a number: ");
    // scanf("%d",&a[i]);
    // for ( i = 1,b = a[i],c = a[i]; i < 4; i++)
    // {
    //     printf("Enter a number: ");
    //     scanf("%d",&a[i]);
    //     if (b>a[i])
    //         b = a[i];
    //     if (c<a[i])
    //         c = a[i];
    // }
    // printf("Max is %d\n",c);
    // printf("Min is %d\n",b);

    //This program reverses an array
    // int a,b,c,i;
    // printf("Enter the size of array: ");
    // scanf("%d",&a);
    // int arr[a];
    // for ( i = 0; i < a; i++)
    // {
    //     printf("Enter a number: ");
    //     scanf("%d",&arr[i]);
    // }
    // for ( i = a-1; i >=0 ; i--)
    //     printf("%d ",arr[i]);

    //This program checks if x,y belongs to array is equal to x+y=z(not completed)
    // int a,b,c,d;
    // int arr[10] = {12,223,34,1-34,3,4-32,0,543,678,0,0,-234};
    // for ( i = 0; i < count; i++)
    // {
    //     for (size_t i = 0; i < count; i++)
    //     {
    //         /* code */
    //     }
    // }
    
    //This program bubble sorts the array
    // int d,i;
    // int arr[10] = { 324,4,1,3,41,1,443,2,11,-14 };
    // printf("{");
    // for ( i = 0; i < 10; i++)
    //     printf("%d,",arr[i]);
    // printf("}\n");
    // while (1)
    // {
    //     for ( i = 1,d = 0; i < 10; i++)
    //     {
    //         if (arr[i]<arr[i-1])
    //         {
    //             arr[i] = arr[i-1]+arr[i];
    //             arr[i-1] = arr[i]-arr[i-1];
    //             arr[i] = arr[i]-arr[i-1];
    //             d++;
    //         }
    //     }
    //     if (d == 0)
    //         break;
    // }
    // printf("{");
    //     for ( i = 0; i < 10; i++)
    //         printf("%d,",arr[i]);
    //     printf("}\n");

    //This program rotates an array
    // int a,i,b,d;
    // printf("Enter size of array: ");
    // scanf("%d",&a);
    // int arr[a];
    // for ( i = 0; i < a; i++)
    // {
    //     printf("Enter a number: ");
    //     scanf("%d",&arr[i]);
    // }
    // printf("Enter rotation index");
    // scanf("%d",&b);
    // printf("{");
    // for( i = 0; i < a; i++)
    // {
    //     if (b>a-1)
    //         b = 0;
    //     printf("%d, ",arr[b]);
    //     b++;
    // }
    // printf("}");
    
    //This program adds two sorted arrays 
    int i,a,b,c,j,k,d;
    printf("Enter size of array: ");
    scanf("%d",&j);
    int arr[j];
    for ( i = 0; i < j; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }
    printf("Enter size of array: ");
    scanf("%d",&k);
    int brr[k];
    for ( i = 0; i < k; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&brr[i]);
    }
    int crr[j+k];
    for ( i = 0,a = 0,b = 0; i < j+k; i++)
    {
        if (b==k && a!=j)
        {
            crr[i] = arr[a];
            a++;
            continue;
        }  
        if (a==j)
        {
            crr[i] = brr[b];
            b++;
            continue;
        }
        if (arr[a]>brr[b])
        {
            crr[i] = brr[b];
            b++;
        }
        else
        {
            crr[i] = arr[a];
            a++;
        }
        
    }
    for ( i = 0; i < j+k; i++)
        printf("%d ",crr[i]);


}