//  //This program calculates the population at the end of each year for the past decade as well as the upcoming decade.
#include<stdio.h>
int main ()
{
    int a,i;
    float d,f;
    printf("Enter current population: ");
    scanf("%f",&d);
    printf("Enter current year: ");
    scanf("%d",&a);
    printf("\nThe population at the end of each year for the past decade is -- \n");
    for ( i = 0 ,f = d; i < 10; i++)
    {
        a--;
        f = (f*100)/110;
        printf("%d -- %.0f\n",a,f);
    }
    printf("\nThe population at the end of each year for the upcoming decade is -- \n");
    for ( i = 0,a = a+10 ,f = d; i < 10; i++)
    {
        a++;
        f = (f*110)/100;
        printf("%d -- %.0f\n",a,f);
    }    
}