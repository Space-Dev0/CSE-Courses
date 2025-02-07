 //This program convert a given number into words
#include<stdio.h>
int main(){
    int a,b,c,d,e,f,g;
    c = 0;
    printf("Enter a number: ");
    scanf("%d",&a);
    d = a;
    while (d>0)
    {
        d = d/10;
        c++;
    }
    while (c>=1)
    {
        for ( d = c-1, e = 1 ; d >0 ; d--)
        {e = e*10;}
        f = a/e;
        g = f%10;
        switch (g)
        {
        case 1:
            printf("One ");
            break;
        case 2:
            printf("Two ");
            break;
        case 3:
            printf("Three ");
            break;
        case 4:
            printf("Four ");
            break;
        case 5:
            printf("Five ");
            break;
        case 6:
            printf("Six ");
            break;
        case 7:
            printf("Seven ");
            break;
        case 8:
            printf("Eight ");
            break;
        case 9:
            printf("Nine ");
            break;
        case 0:
            printf("Zero ");
            break;
        default:
            break;
        }
        c--;
    }  
}