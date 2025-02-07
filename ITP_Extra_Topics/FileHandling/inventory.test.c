#include <stdio.h>
#include <string.h>

struct inventory
{
    char name[30];
    int item_no;
    float price;
    int qty;
};

int main()
{
    FILE *fp = fopen("inventory.txt", "a");
    //fputs("Item No.\tName\tPrice\tQuantity\n", fp);
    int n;
    printf("Enter the no. of Items: ");
    scanf("%d", &n);
    struct inventory inv[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Item no : ");
        scanf("%d", &inv[i].item_no);
        fprintf(fp, "%d\t", inv[i].item_no);
        getchar();

        printf("Enter Item name: ");
        fgets(inv[i].name, 30, stdin);
        inv[i].name[strcspn(inv[i].name, "\n")] = '\0';
        fprintf(fp, "%s\t", inv[i].name);

        printf("Enter Price: ");
        scanf("%f", &inv[i].price);
        fprintf(fp, "%.2f\t", inv[i].price);

        printf("Enter Quantity: ");
        scanf("%d", &inv[i].qty);
        fprintf(fp, "%d\n", inv[i].qty);
    }
//    //fseek(fp, 0, 0);
//     char temp[100];
//     /* fscanf(fp, "%[^\n]", temp);
//     printf("%s", temp);
//     fseek(fp,strlen(temp),0);*/
//     for (int i = 0; i < n ; i++)
//     {
//         // fscanf(fp, "%d %s %f %d", &inv[i].item_no, inv[i].name, &inv[i].price,&inv[i].qty);
//         // fprintf(stdout,"%d %s %f %d\n", inv[i].item_no, inv[i].name, inv[i].price,inv[i].qty);
//         fscanf(fp," %[^\n] ",temp);
//         puts(temp);
//     }
    fclose(fp);
    return 0;
}