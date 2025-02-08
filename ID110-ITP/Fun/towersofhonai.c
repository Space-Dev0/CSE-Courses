#include<stdio.h>

void honai(int n, char from, char to, char aux)
{
    if (n == 1) 
    {
        printf("Move disc 1 from %c -- %c\n",from,to);
        return;
    }
    honai(n-1,from,aux,to);
   
    printf("Move disc %d from %c -- %c\n",n,from,to);
    honai(n-1,aux,to,from);
}

int main()
{
    int i;
    char a ='A',b = 'B',c = 'C';
    printf("Enter no. of Discs: ");
    scanf("%d",&i);
    honai(i,a,b,c);
}