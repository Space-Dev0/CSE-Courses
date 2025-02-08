#include<stdio.h>

int main()
{
    int i,a,arr[10];
    float b,brr[10];
    char c,crr[10];
    
    int* o,*j;
    float* k,*l;
    char* m,*n;

    for ( i = 0; i < 10; i++)
    {
        i[arr] = 10*(i+1);
        brr[i] = i+0.912;
        if (i%2==0)
            crr[i] = 'a';
        else crr[i] = 'b';
    }

    a = 100;
    b = 12.345;
    c = 'G';
    o = &a;
    j = arr;
    k = &b;
    l = brr;
    m = &c;
    n = crr;

    for ( i = 0; i < 10; i++)
    {
        printf("%d ",*(j+i));
    }
    printf("\n");
    for ( i = 0; i < 10; i++)
    {
        printf("%d ",*j+i);
    }
    printf("\n");
    for ( i = 0; i < 10; i++)
    {
        printf("%d ",j[i]);
    }
    printf("\n");
    for ( i = 0; i < 10; i++)
    {
        printf("%d ",i[j]);
    }
    
}