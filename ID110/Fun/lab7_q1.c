#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char rollNo[10];
    char *name;
    unsigned short int age;
    char department[6];
    char sportID[4];
};

struct sport
{
    char id[4];
    char sportName[50];
    int numOfEquipments;
    char **equipment;
};

void inputTable1(struct student *pData, int n)
{
    static int i = 0;
    if (i == n)
        return;
    printf("Enter Student-%d Roll No: ",i+1);
    scanf("%s",pData[i].rollNo);
    getchar();
    printf("Enter Name of Student-%d: ",i+1);
    pData[i].name = (char *)malloc(1024);
    fgets(pData[i].name,1024,stdin);
    pData[i].name = (char *)realloc(pData[i].name, strlen(pData[i].name) + 1);
    printf("Enter age: ");
    scanf(" %hu", &pData[i].age);
    switch (pData[i].rollNo[0])
    {
    case 'A':
        strcpy(pData[i].department, "AI-DS");
        break;
    case 'C':
        strcpy(pData[i].department, "CSE");
        break;
    case 'M':
        strcpy(pData[i].department, "M&C");
        break;
    default:
        strcpy(pData[i].department, "N/A");
        break;
    }
    printf("Enter Sport ID: ");
    scanf("%s", pData[i].sportID);
    i++;
    inputTable1(pData, n);
}

void inputTable2(struct sport *sData, int n)
{
    for (register int i = 0; i < n; i++)
    {
        printf("Enter data for table 2:\n");
        printf("Enter ID: ");
        scanf("%s", sData[i].id);
        getchar();
        printf("Enter sport name: ");
        fgets(sData[i].sportName, 50, stdin);
        printf("Enter Number of Equipments: ");
        scanf("%d", &sData[i].numOfEquipments);
        sData[i].equipment = (char **)malloc(sData[i].numOfEquipments * sizeof(char *));
        for (register int j = 0; j < sData[i].numOfEquipments; j++)
        {
            sData[i].equipment[j] = (char *)malloc(1024);
            printf("Enter Eqipment %d: ",j);
            scanf("%s", sData[i].equipment[j]);
            sData[i].equipment[j] = (char *)realloc(sData[i].equipment[j], strlen(sData[i].equipment[j]) + 1);
        }
    }
}

void printTables (struct student *pData,struct sport *sData,int n, int m)
{
    printf("Table 1:\n");
    //printf("");
}

int main()
{
    int n,m;
    printf("Enter number of students: ");
    scanf("%d",&n);
    printf("Enter number of sports: ");
    scanf("%d",&m);
    getchar();
    struct student pData[n];
    struct sport sData[m];
    inputTable1(pData,n);
    inputTable2(sData,m);
    return 0;
}


