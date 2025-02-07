#include<stdio.h>
#include<stdlib.h>
#include<string.h>

union data
{
    int x;
    float y;
    char z;
};

int main()
{
    union data d;
    printf("Enter x: ");
    scanf("%d",&d.x);
    // printf("Enter z: ");
    // scanf(" %c",&d.z);
    // printf("Enter y: ");
    // scanf("%f",&d.y);
    // printf("%d %f %c\n",d.x,d.y,d.z);
    d.y = 100.234;
    printf("%f\n%d\n",d.y,d.x);
    
    return 0;
}