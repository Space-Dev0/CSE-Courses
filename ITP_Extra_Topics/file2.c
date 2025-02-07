#include<stdio.h>

int main()
{
    FILE *fs, *ft;
    char ch;

    fs = fopen("file.c", "r");
    ft=fopen("ramesh.c","w");
    while(1)
    {
        ch = fgetc(fs);
        if(ch == EOF)
            break;

        fputc(ch,ft);
    }

    fclose(fs);
    fclose(ft);

    return 0;
}