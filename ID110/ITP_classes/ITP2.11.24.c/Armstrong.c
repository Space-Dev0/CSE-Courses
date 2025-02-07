#include<stdio.h>

int armstrong(int a){
    int b,c;
    if(a==0) return 0;
    b = a%10;
    c = b*b*b+armstrong(a/10);
    
}

int main()
{
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);
    a = armstrong(a);
    printf("%d\n",a);
}