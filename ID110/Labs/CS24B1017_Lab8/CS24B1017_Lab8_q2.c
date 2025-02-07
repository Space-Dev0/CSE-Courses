#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct length
{
    int feet;
    float inches;
};


int main()
{
    struct length length1,length2,length3;
    printf("Enter 1'st Distance (feet inch): ");
    scanf("%d %f",&length1.feet,&length1.inches);
    printf("Enter 2'nd Distance (feet inch): ");
    scanf("%d %f",&length2.feet,&length2.inches);
    length3.feet = length1.feet+length2.feet+(int)((length1.inches+length2.inches)/12);
    length3.inches = length1.inches+length2.inches;
    while ((int)length3.inches>12)
    {
        length3.inches = length3.inches - 12;
    }
    printf("Sum = %d'- %.2f\"\n",length3.feet,length3.inches);
    
}