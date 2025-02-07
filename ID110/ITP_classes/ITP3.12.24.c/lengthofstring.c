#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0, count = 0;
    char A[25], B[25], C[49];

    printf("Enter a string: ");
    do
    {
        scanf("%c", A + i);
        i++;
    } while (A[i - 1] != '\n');

    printf("Enter a string: ");
    i = 0;
    do
    {
        scanf("%c", B + i);
        i++;
    } while (B[i - 1] != '\n');

    for (i = 0; A[i] != '\n'; i++)
    {
        C[i] = A[i];
    }

    int j = 0;

    do
    {
        C[i] = B[j];
        j++;
        i++;
    } while (B[j - 1] != '\n');
    
    printf("%s", C);
}
