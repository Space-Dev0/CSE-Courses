#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp_num = fopen("num.txt", "w");
    if (fp_num == NULL)
    {
        exit(1);
    }
    int n;
    printf("Enter How many Numbers: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        // fprintf(fp_num, "%d ", temp);
        putw(temp,fp_num);
    }
    fclose(fp_num);
    fp_num = fopen("num.txt","r");
    int temp;
    FILE *fp_even = fopen("even.txt", "w"), *fp_odd = fopen("odd.txt", "w");
    for (int i = 0; i < n; i++)
    {
        temp = getw(fp_num);
        if (temp % 2 == 0)
        {
            putw(temp, fp_even);
        }
        else
            putw(temp, fp_odd);
    }
    printf("%d",getw(fp_even));
    fclose(fp_num);
    fclose(fp_even);
    fclose(fp_odd);
    return 0;
}