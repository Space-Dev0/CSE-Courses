#include<stdio.h>

int LCM(int,int);
int RecurrsiveLcm(int*,int);
int RecurrsiveGcd(int*,int);
int main()
{
    int a,i;
    printf("Enter size of array: ");
    scanf("%d",&a);
    int arr[a];
    printf("Enter elements of array: " );
    for ( i = 0; i < a; i++)
        scanf("%d",&arr[i]);
    
    printf("The LCM of the numbers is: %d\n",RecurrsiveLcm(arr,a));
    printf("The GCD of the numbers is: %d\n",RecurrsiveGcd(arr,a));
    return 0;
}

int LCM(int m,int n)
{
    int i;  
    if (n <= 1 || m <= 1)
        return m*n;
        /*This is the base case here if one of the number is 1 
        it will return the number itself*/
    else
    {   for ( i = m; i >0 ; i--)
        {
            if (i==1)
            {
                m = m*n;
                n = 1;
                break;
            }
            else if (n%i==0 && m%i == 0)
            {
                m = m/i;
                n = n/i;
                break;
            }
            
        }
        return i * LCM(m,n);
    }    
}

int RecurrsiveLcm(int* arr ,int a)
{
    if(a==1)
        return LCM(arr[0],arr[1]);
    else
        return LCM(LCM(arr[a-2],arr[a-1]),RecurrsiveLcm(arr,a-1)); 
}

int RecurrsiveGcd(int* arr,int a)
{
    if(a==1)
        return arr[0];
    else
    {
        arr[a-2]=(arr[a-1]*arr[a-2])/LCM(arr[a-2],arr[a-1]);
        return RecurrsiveGcd(arr,a-1);
    } 
}