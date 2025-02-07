#include <stdio.h>

int trap(int *height, int heightSize);

int main()
{
    int heightSize, i;
    printf("Enter size of height array: ");
    scanf("%d", &heightSize);
    int height[heightSize];
    for (i = 0; i < heightSize; i++)
        scanf("%d", height + i);
    printf("\n%d\n",trap(height,heightSize));
}

int trap(int *height, int heightSize)
{
    int i,j,total = 0 ,temp,k;

    for ( i = 0; i < heightSize-1; i++)
    {
        for ( j = i+1; height[i] > height[j] && j<heightSize; j++);
        
        if (j==heightSize) continue;
        
        temp = height[i]*(j-i-1);

        for ( k = i+1; k < j; k++)
            temp -= height[k];
        
        total = total + temp;

        i = j-1;
    }
    
    return total;
}