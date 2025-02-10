#include <stdio.h>
#include <string.h>

int main()
{
    char input[15];
    scanf("%s", input);
    if (strcmp(input, "vertebrado") == 0)
    {
        scanf("%s", input);
        if (strcmp(input, "ave") == 0)
        {
            scanf("%s", input);
            if (strcmp(input, "carnivoro") == 0)
            {
                printf("aguia\n");
            }
            else
            {
                printf("pomba\n");
            }
        }
        else
        {
            scanf("%s", input);
            if (strcmp(input, "onivoro"))
            {
                printf("homem\n");
            }
            else
            {
                printf("vaca\n");
            }
        }
    }
    else
    {
        scanf("%s", input);
        if (strcmp(input, "inseto") == 0)
        {
            scanf("%s", input);
            if (strcmp(input, "hematofago") == 0)
            {
                printf("pulga\n");
            }
            else
            {
                printf("lagarta\n");
            }
        }
        else
        {
            scanf("%s", input);
            if (strcmp(input, "hematofago") == 0)
            {
                printf("sanguessuga\n");
            }
            else
            {
                printf("minhoca\n");
            }
        }
    }
    return 0;
}