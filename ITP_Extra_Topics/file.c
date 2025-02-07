#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("unions.c", "r");


    if(fp == NULL)
    {
        printf("The file doesn't exist");
        exit(1);
    }
    int totalCount=0,tabCount=0,newlineCount=0,spaceCount=0;
    while(1)
    {
        ch = getc(fp);
        if(ch == EOF)
            break;
        if (ch == '\t')
            tabCount++;
        if(ch == '\n')
            newlineCount++;
        if(ch == ' ')
            spaceCount++;

        printf("%c",ch);
        totalCount++;
    }
    fclose(fp);
    printf("\n\nStats:\n");
    printf("Total Char: %d\n",totalCount);
    printf("Total tabs: %d\n",tabCount);
    printf("Total new lines: %d\n",newlineCount);
    printf("Total spaces: %d\n",spaceCount);

}