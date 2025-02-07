#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    struct data
    {
        char name[30];
        int age;
        char gender;
    }d1;
    
    FILE *fp = fopen("bioData.txt","w");
    if (fp == NULL)
    {
        printf("err: File not opened");
        exit(1);
    }
    printf("Enter Name: ");
    fgets(d1.name,30,stdin);
    fputs("Name: ",fp);
    fputs(d1.name,fp); 
    printf("Enter Age: ");
    scanf("%d",&d1.age);
    fputs("\nAge: ",fp);
    fprintf("%d",d1.age,fp);
    printf("\nEnter gender: ");
    scanf("%c",&d1.gender);
    fputs("\nGender: ",fp);
    fputs((char*)d1.gender,fp);
    fclose(fp);
   // fp = fopen("ram.txt","r");
    // if (fp == NULL)
    // {
    //     printf("err: File not opened");
    //     exit(1);
    // }
    // while (1)
    // {
    //     /* code */
    // }
    
}