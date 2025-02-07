#include<stdio.h>
#include<stdlib.h>

enum days
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday = 10,
    Thursday,
    Friday,
    Saturday
};

int main ()
{
    // enum days d1;
    printf("%d\n",Thursday);
    return 0;
}