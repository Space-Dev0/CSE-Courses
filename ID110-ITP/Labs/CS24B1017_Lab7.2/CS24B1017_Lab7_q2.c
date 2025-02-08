#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *inputStr = (char *)malloc(1024);
    printf("Enter string inputStr: ");
    scanf("%[^\n]s", inputStr);
    inputStr = (char *)realloc(inputStr, strlen(inputStr) + 1);
    char revStr[strlen(inputStr) + 1];
    for (int i = strlen(inputStr)-1,j=0; i >=0; i--,j++)
        revStr[j] = inputStr[i]; 
    revStr[strlen(inputStr)] = '\0';
    printf("Orignal String : %s\n",inputStr);
    printf("Reversed String : %s\n",revStr);
}