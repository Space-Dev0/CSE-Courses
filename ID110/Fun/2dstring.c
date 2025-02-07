#include<stdio.h>
#include<string.h>

int main()
{
    char arr[3][4];
    for (int i = 0; i < 3; i++)
    {
        scanf("%s",arr[i]);
    }
    printf("[");
    for (int i = 0; i < 3; i++)
    {
        printf("[%c]",arr[i]);
    }
    printf("]\n");   

}