#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct s_name
    {
        char sub_name[50];
        int marks;
    };

    struct Subjects
    {
        char name[50];
        float cgpa;
        struct s_name s_info[5];
    } S[n];
    for (i = 0; i < n; i++)
    {
        float total = 0;
        printf("Enter the name of the Student: ");
        scanf(" %[^\n]s", S[i].name);

        for (int j = 0; j < 5; j++)
        {
            printf("Enter Name of Subject: ");
            scanf(" %s", S[i].s_info[j].sub_name);
            printf("Enter marks for %s: ", S[i].s_info[j].sub_name);
            scanf("%d", &S[i].s_info[j].marks);
            total += S[i].s_info[j].marks;
        }
        S[i].cgpa = total / 50;
    }

    printf("Name \t Subjects Marks\n");
    for (i = 0; i < n; i++)
    {
        printf("%s : ", S[i].name);
        for (int j = 0; j < 5; j++)
            printf("%s  %d\n", S[i].s_info[j].sub_name, S[i].s_info[j].marks);
        printf("Total: %.0f    CGPA: %.2f\n",S[i].cgpa*50,S[i].cgpa);

    }
}