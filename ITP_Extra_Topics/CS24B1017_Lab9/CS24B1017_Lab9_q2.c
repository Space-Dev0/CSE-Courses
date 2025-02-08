#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students
{
    int ID;
    char name[100];
    int rollNo;
    char branch[100];
};

void finder(int n, struct students S[n])
{
    while (1)
    {
        char command;
        printf("To find Enter:\n");
        printf("f = find with name\nr = find with Roll No.\ni = find with Student ID\ne = exit\n\nEnter: ");
        scanf("%c", &command);
        getchar();
        printf("%c\n", command);
        switch (command)
        {
        case 'f':
            char sname[100];
            printf("Enter name of student: ");
            scanf("[^\n]%s", sname);
            int i;
            for (i = 0; i < n; i++)
            {
                if (strcmp(S[i].name, sname) == 0)
                {
                    printf("Student found at index: %d", i + 1);
                    break;
                }
            }
            if (i == n)
            {
                printf("Student not found!\n");
            }

            break;
        case 'i':
            break;
        case 'r':
            break;
        case 'e':
            break;
        default:
            printf("Invalid choice! Please try again\n");
            break;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct students S[n];

    FILE *fp = NULL;
    fp = fopen("result.txt", "w");
    fprintf(fp, "S.no.\tStudent ID\tName\tRoll No.\tBranch\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%-6d\t", 1 + i);
        printf("Enter details for Student %d:\n", i + 1);
        printf("Student ID: ");
        scanf("%d", &S[i].ID);
        getchar();
        fprintf(fp, "%-10d\t", S[i].ID);
        printf("Student Name: ");
        scanf("%[^\n]s", S[i].name);
        fprintf(fp, "%-7s\t", S[i].name);
        printf("Roll No: ");
        scanf("%d", &S[i].rollNo);
        getchar();
        fprintf(fp, "%-8d\t", S[i].rollNo);
        printf("Branch: ");
        scanf("%[^\n]s", S[i].branch);
        fprintf(fp, "%-6s\n", S[i].branch);
    }
    getchar();
    printf(fp, "S.no,Student ID,Name,Roll No,Branch");
    for (int i = 0; i < n; i++)
    {
        printf("%d,%d,%s,%d,%s\n",i+1,S[i].ID,S[i].name,S[i].rollNo,S[i].branch);
    }
    fclose(fp);

    finder(n, S);
}