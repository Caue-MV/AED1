#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int convert_to_decimal(char *num, char *base)
{
    unsigned int decimal = 0;
    if (strcmp(base, "bin") == 0)
    {
        decimal = strtol(num, NULL, 2);
    }
    else if (strcmp(base, "dec") == 0)
    {
        decimal = strtol(num, NULL, 10);
    }
    else if (strcmp(base, "hex") == 0)
    {
        decimal = strtol(num, NULL, 16);
    }
    return decimal;
}

void convert_to_bases(unsigned int decimal, char *output_hex, char *output_bin)
{
    sprintf(output_hex, "%x", decimal);
    output_bin[0] = '\0';
    for (int i = 31; i >= 0; i--)
    {
        output_bin[31 - i] = ((decimal >> i) & 1) + '0';
    }
    output_bin[32] = '\0';
    int leading_zeros = 1;
    int j = 0;
    for (int i = 0; output_bin[i] != '\0'; i++)
    {
        if (output_bin[i] == '1')
            leading_zeros = 0;
        if (!leading_zeros)
            output_bin[j++] = output_bin[i];
    }
    output_bin[j] = '\0';
    if (strlen(output_bin) == 0)
        strcpy(output_bin, "0");
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int caso = 1; caso <= N; caso++)
    {
        char num[50], base[5];
        scanf("%s %s", num, base);
        unsigned int decimal = convert_to_decimal(num, base);
        char output_hex[50], output_bin[50];
        convert_to_bases(decimal, output_hex, output_bin);
        printf("Case %d:\n", caso);
        if (strcmp(base, "dec") != 0)
            printf("%u dec\n", decimal);
        if (strcmp(base, "hex") != 0)
            printf("%s hex\n", output_hex);
        if (strcmp(base, "bin") != 0)
            printf("%s bin\n", output_bin);
        if (caso < N)
            printf("\n");
    }
    printf("\n");
    return 0;
}