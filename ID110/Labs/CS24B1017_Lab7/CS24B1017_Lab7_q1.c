#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, k, table1_rowSize, table1_columnSize, table2_rowSize, table2_columnSize;
    printf("Enter the number of rows and columns for Table-1: ");
    scanf("%d %d", &table1_rowSize, &table1_columnSize);
    char ***table1 = (char ***)malloc((table1_rowSize + 1) * sizeof(char *));
    for (i = 0; i < table1_rowSize + 1; i++)
    {
        table1[i] = (char **)malloc(table1_columnSize * sizeof(char *));
        for (j = 0; j < table1_columnSize; j++)
        {
            table1[i][j] = (char *)malloc(1024 * sizeof(char));
        }
    }
    printf("Enter Column names: ");
    for (i = 0; i < table1_columnSize; i++)
    {
        scanf("%s", table1[0][i]);
        table1[0][i] = (char *)realloc(table1[0][i], (strlen(table1[0][i]) + 1));
    }
    for (i = 1; i < table1_rowSize + 1; i++)
    {
        for (j = 0; j < table1_columnSize; j++)
        {
            if (strcmp(table1[0][j], "Department") == 0 || strcmp(table1[0][j], "department") == 0)
            {
                table1[i][j] = (char *)realloc(table1[i][j], 6);
                switch (table1[i][0][0])
                {
                case 'C':
                    table1[i][j] = "CSE";
                    break;
                case 'A':
                    table1[i][j] = "AI-DS";
                    break;
                case 'M':
                    table1[i][j] = "M&C";
                    break;
                default:
                    table1[i][j] = " ";
                    break;
                }
                continue;
            }

            printf("Enter %s of student %d: ", table1[0][j], i);
            scanf(" %[^\n]s", table1[i][j]);
            table1[i][j] = (char *)realloc(table1[i][j], (strlen(table1[i][j]) + 1));
        }
    }
    printf("Enter the number of rows and columns for Table-2: ");
    scanf("%d %d", &table2_rowSize, &table2_columnSize);
    char ***table2 = (char ***)malloc((table2_rowSize + 1) * sizeof(char *));
    for (i = 0; i < table2_rowSize + 1; i++)
    {
        table2[i] = (char **)malloc(table2_columnSize * sizeof(char *));
        for (j = 0; j < table2_columnSize; j++)
        {
            table2[i][j] = (char *)malloc(1024 * sizeof(char));
        }
    }
    printf("Enter Column names: ");
    for (i = 0; i < table2_columnSize; i++)
    {
        scanf("%s", table2[0][i]);
        table2[0][i] = (char *)realloc(table2[0][i], (strlen(table2[0][i]) + 1));
    }
    for (i = 1; i < table2_rowSize + 1; i++)
    {
        for (j = 0; j < table2_columnSize; j++)
        {
            if (strcmp(table2[0][j], "Equipment") == 0 || strcmp(table2[0][j], "equipment") == 0)
            {
                int total_equipments;
                printf("Enter total no. of Equipments of Sport %d: ", i);
                scanf("%d", &total_equipments);
                char equipments[1024];
                printf("Eqipment 1: ");
                scanf("%s", equipments);
                equipments[strlen(equipments)] = ',';
                equipments[strlen(equipments) + 1] = ' ';
                equipments[strlen(equipments) + 2] = '\0';
                for (k = 1; k < total_equipments; k++)
                {
                    printf("Equipment %d: ",k+1);
                    if (k == total_equipments-1)
                    {
                        strcat(table1[i][j],equipments);
                        continue;
                    }
                    char temp[1024];
                    scanf("%s", temp);
                    temp[strlen(temp)] = ',';
                    temp[strlen(temp) + 1] = ' ';
                    temp[strlen(temp) + 2] = '\0';
                    strcat(equipments, temp);
                }
                strcpy(table2[i][j],equipments);
                continue;
            }
            printf("Enter %s of sport %d: ", table2[0][j], i);
            scanf(" %[^\n]s", table2[i][j]);
            table2[i][j] = (char *)realloc(table2[i][j], (strlen(table2[i][j]) + 1));
        }
    }

    printf("Table 1:\n");
    for (i = 0; i < table1_rowSize + 1; i++)
    {
        for (j = 0; j < table1_columnSize; j++)
        {
            if (j == table1_columnSize - 1)
                printf("%s", table1[i][j]);

            else
                printf("%s - ", table1[i][j]);
        }
        printf("\n");
    }
    printf("######################################################\n");

    printf("Table 2:\n");
    for (i = 0; i < table2_rowSize + 1; i++)
    {
        for (j = 0; j < table2_columnSize; j++)
        {
            if (j == table2_columnSize - 1)
                printf("%s", table2[i][j]);

            else
                printf("%s - ", table2[i][j]);
        }
        printf("\n");
    }
    printf("######################################################\n");
}