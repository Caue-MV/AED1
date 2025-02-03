#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isHexadecimal(char *str)
{
    return (strncmp(str, "0x", 2) == 0) || (strlen(str) > 1 && str[1] == 'x');
}

int main()
{
    char input[50];
    while (1)
    {
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }
        input[strcspn(input, "\n")] = 0;
        long long num = atoll(input);
        if (num < 0)
        {
            break;
        }
        if (isHexadecimal(input))
        {
            printf("%lld\n", (long long)strtol(input, NULL, 16));
        }
        else
        {
            printf("0x%llX\n", num);
        }
    }
    return 0;
}