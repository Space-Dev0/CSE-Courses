#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define CMAX 100

char binaryToChar(char *);

int main()
{
    FILE *fp = NULL;
    char fName[CMAX];
    printf("Enter file name: ");
    scanf("%s", fName);
    fp = fopen(fName, "r");
    if (fp == NULL)
    {
        printf("err: file '%s' was not opened\n", fName);
        exit(1);
    }
    else
        printf("\n'%s' opened successfully\n", fName);

    char buf[CMAX];
    int i = 0;
    printf("Decoding...\n\n");
    while (!feof(fp))
    {
        fscanf(fp, "%s", buf);
        printf("%c", binaryToChar(buf));
        i++;
    }
    printf("\n\n");
    fclose(fp);
    printf("%s closed successfully\n", fName);
    return 0;
}

char binaryToChar(char *bstr)
{
    int i = 0, numASCII = 0, len = strlen(bstr) - 1;
    while (bstr[i] != '\0')
    {
        if (bstr[i] == '1')
        {
            int num = 1;
            for (int j = 0; j < len - i; j++)
                num *= 2;
            numASCII += num;
        }
        i++;
    }
    return (char)numASCII;
}