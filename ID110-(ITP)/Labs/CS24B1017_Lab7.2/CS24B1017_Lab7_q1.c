#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *inputStr = (char *)malloc(1024);
    printf("Enter string inputStr: ");
    scanf("%[^\n]s", inputStr);
    inputStr = (char *)realloc(inputStr, strlen(inputStr) + 1);
    char copyStr[strlen(inputStr) + 1];
    int i = 0;
    do
    {
        copyStr[i] = inputStr[i];
        i++;
    }while (inputStr[i-1] != '\0');
    
    printf("String copyStr: %s\n", copyStr);
}