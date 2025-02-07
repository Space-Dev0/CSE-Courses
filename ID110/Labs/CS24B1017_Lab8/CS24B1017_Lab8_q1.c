#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct str1
{
    int num1;
};

struct str2
{
    int num2;
};


int main()
{
    struct str1 structure1;
    struct str2 structure2;
    printf("Enter values for num1 and num2: ");
    scanf("%d %d",&structure1.num1,&structure2.num2);
    printf("Sum of two structures: %d\n",structure1.num1+structure2.num2);
    return 0;
}