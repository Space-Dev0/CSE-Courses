#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char A[] = "My name\n";
    char *ptr = "your name\n";
    int i = 0;
    while (A[i] != '\0')
    {
        printf("%c", A[i]);
        i++;
    }

    printf("Enter a string: ");
    char c;
    i = 0;
    do
    {
        scanf("%c", &c);
        A[i] = c;
        i++;
    } while (c != '\n');

    printf("%s", A);

    scanf("%[^\n]s", A);
    gets(A);
    puts(A);
    printf("%s", A);

    // while (*(ptr+i)  != '0')
    // {
    //     printf("%c", *(ptr+i));
    //     i++;
    // }

    printf("%s", ptr + 1);
}