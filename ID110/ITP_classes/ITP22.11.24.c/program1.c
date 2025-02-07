#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, i;

    ptr = (int *)calloc(3, sizeof(int));
    printf("%d\n",sizeof(int));
    if (ptr == NULL)
    {
        printf("Memeory allocation is not possible:");
        exit(1);
    }

    for (i = 0; i < 3; i++)
    {
        printf("Enter the %d value:", i);
        scanf("%d", &ptr[i]);
    }

    //*ptr=50;

    /*for(i=0;i<3;i++)
        {
            printf("value at ptr[%d] is %d:\n",i, ptr[i]);
            //scanf("%d", &ptr[0]);
        }*/
    ptr = realloc(ptr, 7);
    for (i = 3; i < 10; i++)
    {
        // printf("value at ptr[%d] is %d:\n",i, ptr[i]);
        scanf("%d", &ptr[i]);
    }
    for (i = 0; i < 10; i++)
    {
        printf("value at ptr[%d] is %d:\n", i, ptr[i]);
        // scanf("%d", &ptr[0]);
    }
    free(ptr);
    return 0;
}