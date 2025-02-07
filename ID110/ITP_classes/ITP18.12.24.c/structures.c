#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(8)

struct student
{
    char name[50];
    struct subname
    {
        char sub_name[50];
        int marks;
        int maxmarks;
    } subjects[5];
    int totalO;
    int totalMM;
    float percentage;
};



void input(int n, struct student *S[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter name of Student %d: ", i);
        scanf("%[^\n]s", S[i]->name);
        int totalMM = 0, totalO = 0;
        for (int j = 0; j < 5; j++)
        {
            printf("Enter name of %d Subject: ", j);
            scanf("%s", S[i]->subjects[j].sub_name);
            printf("Enter Max Marks for %s: ", S[i]->subjects[j].sub_name);
            scanf("%d", &S[i]->subjects[j].maxmarks);
            printf("Enter OBTAINED marks: ");
            scanf("%d", &S[i]->subjects[j].marks);
            totalMM = totalMM + S[i]->subjects[j].maxmarks;
            totalO = totalO + S[i]->subjects[j].marks;
        }
        S[i]->totalMM = totalMM;
        S[i]->totalO = totalO;
        S[i]->percentage = ((float)S[i]->totalO / (float)S[i]->totalMM) * 100;
    }
}

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student S[n];
}

