#include<stdio.h>
#include<math.h>

void Honai(int* ,int*,int*,int[], int[], int[],int,int);

int main()
{
    int numDiscs,i,b,c;
    printf("Enter the number of Discs: ");
    scanf("%d",&numDiscs);
    int A[numDiscs],B[numDiscs],C[numDiscs];
    for ( i = 0,b = numDiscs; i < numDiscs; i++,b--)
    {
        A[i] = b;
        B[i] = 0;
        C[i] = 0;
    }
    Honai(&A[0],&B[0],&C[0],A,B,C,numDiscs,numDiscs);
}

void Honai(int* a,int* b,int* c,int A[],int B[],int C[],int numDiscs,int numDiscsCopy)
{

    int i;
    if (numDiscsCopy==1)
    {
        C[numDiscs-1] = A[0];
        A[0] = 0;
        printf("A={ ");
        for ( i = 0; i < numDiscs; i++)
            printf("%d ",a[i]);
        printf("}\n");
        printf("B={ ");
        for ( i = 0; i < numDiscs; i++)
            printf("%d ",b[i]);
        printf("}\n");
        printf("C={ ");
        for ( i = 0; i < numDiscs; i++)
            printf("%d ",c[i]);
        printf("}\n\n");        
        return;
    }

    
    
    Honai(a,b,c,A,C,B,numDiscs,numDiscsCopy-1);

    C[numDiscs-numDiscsCopy] = A[numDiscsCopy-1];
    A[numDiscsCopy-1] = 0;
    
    printf("A={ ");
    for ( i = 0; i < numDiscs; i++)
        printf("%d ",a[i]);
    printf("}\n");
    printf("B={ ");
    for ( i = 0; i < numDiscs; i++)
        printf("%d ",b[i]);
    printf("}\n");
    printf("C={ ");
    for ( i = 0; i < numDiscs; i++)
        printf("%d ",c[i]);
    printf("}\n\n");



    Honai(a,b,c,B,A,C,numDiscs,numDiscsCopy-1);

}

