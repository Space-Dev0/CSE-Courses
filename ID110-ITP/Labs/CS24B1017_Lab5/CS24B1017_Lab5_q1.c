#include <stdio.h>

void sharpen(int a, int (*image)[a]);        
void boxBlurr(int a, int (*image)[a]);
void emboss(int a, int (*image)[a]);
void subMatrix(int a, int (*image)[a], int i, int j, int (*temp2)[3]);
void kernelMultiplier(int a, int (*image)[a], int (*kernel)[3]);

int main()
{
    int a, i, j;
    char operation;
    do
    {
        printf("Enter the size of matrix: ");
        scanf("%d", &a);
        if (a < 1 || a > 100)
        {
            printf("## Size of matrix should be between 1 and 100 ##\n");
        }
    } while (a < 1 || a > 100);

    int image[a][a];
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            do
            {
                scanf("%d", &image[i][j]);
                if (image[i][j] > 255 || image[i][j] < 0)
                    printf("## Enter values between 0 and 255 ##\n");
            } while (image[i][j] > 255 || image[i][j] < 0);
        }
    }
    printf("What operation do you want?\n\n1 - Box Blur\n2 - Sharpen\n3 - Emboss\nEnter: ");
    do
    {
        scanf(" %c", &operation);
        if (operation != '1' && operation != '2' && operation != '3')
        {
            printf("Enter 1, 2 or 3:\n1 - Box Blur\n2 - Sharpen\n3 - Emboss\n\nEnter: ");
        }

    } while (operation != '1' && operation != '2' && operation != '3');

    printf("\n");

    switch (operation)
    {
    case '1':
        boxBlurr(a, image);
        break;
    case '2':
        sharpen(a, image);
        break;
    default:
        emboss(a, image);
        break;
    }

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void boxBlurr(int a, int (*image)[a])
{
    int i, j, m, n, sum, q;
    int temp[a][a];

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            sum = 0;
            q = 0;
            for (m = i - 1; m < i + 2; m++)
            {
                for (n = j - 1; n < j + 2; n++)
                {

                    if (m < 0 || m >= a || n < 0 || n >= a)
                    {
                        continue;
                    }
                    else
                    {
                        sum = sum + image[m][n];
                        q++;
                    }
                }
            }

            temp[i][j] = sum / q;
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}

void sharpen(int a, int (*image)[a])
{
    int kernel[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};
    kernelMultiplier(a, image, kernel);
    return;
}

void emboss(int a, int (*image)[a])
{
    int kernel[3][3] = {{-2, -1, 0}, {-1, 1, 1}, {0, 1, 2}};
    kernelMultiplier(a, image, kernel);
    return;
}

void subMatrix(int a, int (*image)[a], int i, int j, int (*temp2)[3])
{
    int m, n, k, l;
    k = 0;
    l = 0;
    for (m = i - 1; m < i + 2; m++)
    {
        for (n = j - 1; n < j + 2; n++)
        {

            if (m < 0 || m >= a || n < 0 || n >= a)
                temp2[k][l] = 0;
            else
                temp2[k][l] = image[m][n];
            l++;
            if (l > 2)
            {
                l = 0;
                k++;
            }
        }
    }
}

void kernelMultiplier(int a, int (*image)[a], int (*kernel)[3])
{
    int i, j,m, n, sum;
    int temp1[a][a];
    int temp2[3][3];

    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            subMatrix(a, image, i, j, temp2);
            sum = 0;
            for (m = 0; m < 3; m++)
            {
                for (n = 0; n < 3; n++)
                {
                    sum = sum + temp2[m][n] * kernel[m][n];
                }
            }

            temp1[i][j] = sum;
        }
    }
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            image[i][j] = temp1[i][j];
        }
    }
}
