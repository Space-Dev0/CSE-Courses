#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define pi 25346

#define max(a,b,c) a>b?(a>c?a:(b>c?b:c)):(b>c?b:b<c?c:b)

struct aisehi
{
    int n;
    int m;
    struct aisehi* ptr;   
};


int main()
{    
    struct aisehi mm;
    struct aisehi *cc = &mm;
    printf("%d",cc->ptr->ptr->ptr->ptr);

}