#include <stdio.h>
#include <limits.h>

int x = 10;

void main()
{
    register int x = 20;
    {
        static int x = 30;
        printf("%d ", x);
    }
    printf("%d ", x);
}