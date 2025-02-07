#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
    char* string = (char*)malloc(1024*sizeof(char));
    int wordNumber, i = 0, count = 0;
    printf("Enter the string: ");
    scanf("%[^'\n']s", string);
    string = (char*)realloc(string,strlen(string)+1);
    printf("Enter the word number: ");
    scanf("%d", &wordNumber);
    while (string[i] == ' ')
        i++;
    while (string[i] != '\0')
    {
        if (string[i] == ' ')
        {
            count++;
            i++;
            while (string[i] == ' ')
                i++;
            continue;
        }
        else if (count == (wordNumber - 1))
            printf("%c", string[i]);
        i++;
    }
    printf("\n");
}