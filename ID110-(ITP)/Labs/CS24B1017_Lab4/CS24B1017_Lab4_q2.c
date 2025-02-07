#include<stdio.h>

int findMostFrequent(int* nbh, int size);

void getOTP(int* nbh, int size);

int main()
{
    int size,i;
    printf("Enter the size of order array: ");
    scanf("%d",&size);

    int nbh[size];

    printf("Enter the elements of array: ");
    for ( i = 0; i < size; i++)
        scanf("%d",nbh+i);

    printf("\n:: Blinkit Delivery Service Coverage Report ::\n");
    printf("###################################################\n");
    printf("Most frequently visited neighbourhood : %d\n",findMostFrequent(nbh,size));
    printf("###################################################\n");
    getOTP(nbh,size);
    printf("\n\n");
}

int findMostFrequent(int* nbh, int size)
{
    int i,j,d,e=0,mode;
    for ( i = 0; i < size; i++)
    {
        for ( j = i+1,d = 1; j < size; j++)
        {
            if (*(nbh+i)== *(nbh+j))
                d++;
        }
        if(d>e)
        {
            mode = *(nbh+i);
            e = d;
        }
    }
    return mode;
}

void getOTP(int* nbh, int size)
{
    int i,j,a;
    printf("Additional Logs:\n");
    for ( i = 0; i < size; i++)
        printf("-- Order no.: %d, Nbh. ID: %d, OTP: %p\n",i,*(nbh+i),nbh+i);
}