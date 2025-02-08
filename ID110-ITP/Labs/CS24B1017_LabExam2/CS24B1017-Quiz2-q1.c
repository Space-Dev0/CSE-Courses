#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

#define max(a, b) a > b ? a : b

struct ip_name
{
    char name[50];
    int ip;
};

int binaryToDecimal(char *str)
{
    int i, num = 0, size = strlen(str);
    for (i = 0; i < size + 1; i++)
    {
        if (str[i] == '1')
        {
            int temp = 1;
            for (int j = 0; j < size - i - 1; j++)
            {
                temp *= 2;
            }
            num = num + temp;
        }
    }
    return num;
}

char *binaryToText(char *binary)
{
    int i, size = (strlen(binary) / 8) + 1;
    char *str = (char *)malloc(size);
    int k = 0;
    for (i = 0; i < size - 1; i++)
    {
        int j;
        char *temp = (char *)malloc(9);
        for (j = 0; j < 8; j++)
        {
            temp[j] = binary[k];
            k++;
        }
        temp[j] = '\0';
        str[i] = (char)binaryToDecimal(temp);
    }
    str[size - 1] = '\0';
    return str;
}

void reportPrinter(struct ip_name Eren, struct ip_name Mikasa)
{
    char input[1024];
    printf("Enter String: ");
    scanf("%s", input);
    int *sizeIpDatagram = (int *)malloc(13 * sizeof(int));
    sizeIpDatagram[0] = 5;
    sizeIpDatagram[1] = 5;
    sizeIpDatagram[2] = 9;
    sizeIpDatagram[3] = 17;
    sizeIpDatagram[4] = 17;
    sizeIpDatagram[5] = 4;
    sizeIpDatagram[6] = 14;
    sizeIpDatagram[7] = 9;
    sizeIpDatagram[8] = 9;
    sizeIpDatagram[9] = 17;
    sizeIpDatagram[10] = 33;
    sizeIpDatagram[11] = 33;
    sizeIpDatagram[12] = strlen(input) - 159;
    char **ipDatagram = (char **)malloc(13 * sizeof(char *));
    int k = 0;
    for (int i = 0; i < 13; i++)
    {
        ipDatagram[i] = (char *)malloc(sizeIpDatagram[i]);
        int j;
        for (j = 0; j < sizeIpDatagram[i] - 1; j++)
        {
            ipDatagram[i][j] = input[k];
            k++;
        }
        ipDatagram[i][j] = '\0';
    }

    k = 0;
    printf("Decoded IP Datagram: \n");
    printf("=================================================\n");
    printf("Version: ");
    if (binaryToDecimal(ipDatagram[0]) == 4)
    {
        printf("IPv4\n");
    }
    else if (binaryToDecimal(ipDatagram[0]) == 6)
        printf("IPv6\n");
    printf("Header Length: %d bytes\n", binaryToDecimal(ipDatagram[1]) * 4);
    printf("Type of Service (ToS): %d\n", binaryToDecimal(ipDatagram[2]));
    printf("Total Length: %d bytes\n", binaryToDecimal(ipDatagram[3]));
    printf("ID: %d\n", binaryToDecimal(ipDatagram[4]));
    printf("Flags: %d ", binaryToDecimal(ipDatagram[5]));
    if (binaryToDecimal(ipDatagram[5]) == 2)
        printf("(Don't Fragment)\n");
    else if (binaryToDecimal(ipDatagram[5]) == 1)
        printf("(More Fragment)\n");
    printf("Fragment Offset: %d\n", binaryToDecimal(ipDatagram[6]));
    printf("Time to Live (TTL): %d Hops\n", binaryToDecimal(ipDatagram[7]));
    printf("Protocol: %d", binaryToDecimal(ipDatagram[8]));
    switch (binaryToDecimal(ipDatagram[8]))
    {
    case 6:
        printf(" (TCP)\n");
        break;
    case 17:
        printf(" (UDP)\n");
        break;
    case 27:
        printf(" (RDP)\n");
        break;
    default:
        printf(" (XTP)\n");
        break;
    }
    printf("Header Checksum: %s\n", ipDatagram[9]);

    printf("Source IP: ");
    if (binaryToDecimal(ipDatagram[10]) == -1062729215)
    {
        printf("192.168.10.1 (Eren)\n");
    }
    else
        printf("192.168.10.2 (Mikasa)\n");
    printf("Destination IP: ");
    if (binaryToDecimal(ipDatagram[11]) == -1062729215)
    {
        printf("192.168.10.1 (Eren)\n");
    }
    else
        printf("192.168.10.2 (Mikasa)\n");
    printf("Message: %s\n", binaryToText(ipDatagram[12]));
}

int main()
{
    struct ip_name Mikasa, Eren;
    Eren.ip = -1062729215;
    Mikasa.ip = -1062729214;
    reportPrinter(Eren, Mikasa);
}