#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int size,newIndex;
    char string[25];
    printf("Enter a string: ");
    scanf("%s",string);
    printf("Enter new index: ");
    scanf("%d",&newIndex);
    char *a;
    a = string+newIndex;
    
    for (int i = (-newIndex);a[i]!='\0'; i++)
    {
        printf("%c",a[i]);
    }
    printf("\n");
    for (int i = (-newIndex);a[i]!='\0'; i++)
    {
        printf("%d",i);
    }
    printf("\n");
    
}
