#include <stdio.h>

enum department
{
    CSE,
    AI,
    Mathematics,
    Physics,
    History
};

struct employee
{
    char name[30];
    int age;
    enum department dept;
};

int main()
{
    struct employee e;
    int temp;
   // for (int i = 0; i < 2; i++)
    {
        printf("Enter name of employee: ");
        fflush(stdin);
        fgets(e.name, 30, stdin);
        printf("Enter age: ");
        scanf("%d", &e.age);
        //printf("Enter Department: ");
        //scanf("%d", &temp);
        //scanf("%c");
        fflush(stdin);
        e.dept = AI;
    }

    printf("Data: \n");
    //for (int i = 0; i < 2; i++)
    {
        printf("Name of employee %s: \n",e.name);
        printf("Age: %d\n", e.age);
        printf("Department: %d\n", e.dept);
    }
    return 0;
}
