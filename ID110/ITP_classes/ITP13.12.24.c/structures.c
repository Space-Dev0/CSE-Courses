#include <stdio.h>

int main()
{
    struct student
    {
        char name[31];
        char roll_no[10];
        char gender;
    };

    struct student s[10];
    for (int i = 0; i < 3; i++)
    {
        printf("Enter name of student %d: ", i);
        scanf("%s", s[i].name);
        printf("Enter Roll No. of student %d: ", i);
        scanf(" %s", s[i].roll_no);
        printf("Enter Gender of student %d: ", i);
        scanf(" %c", &s[i].gender);
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Name of student %d: %s        :: Address = %u\n", i,(s[i].name),&(s[i].name));
        printf("Roll No. of student %d: %s    :: Address = %u\n", i,(s[i].roll_no),&(s[i].roll_no));
        printf("Gender of student %d: %c      :: Address = %u\n", i,(s[i].gender),&(s[i].gender));
        
    }
}