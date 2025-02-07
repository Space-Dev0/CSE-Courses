#include<stdio.h>
#include<stdlib.h>
void india();
void usa();
void raichur();

int main()
{
    int i;
    printf("Enter a valur between 0 and 2: ");
    scanf("%d",&i);
    if (i==0)
        india();
    else if (i==1)
        usa();
    else
        raichur();
}

void india()
{
    printf("I am in India");
}

void usa()
{
    printf("I am in Usa");
}

void raichur()
{
    printf("I am in Raichur");
}
`