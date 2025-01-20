#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string[1000], limpo[1000];
    int dia=0, casos, i, j;
    scanf("%d", &casos);
    for (int k = 0; k < casos; k++)
    {
        scanf("%s", string);
        i = 0;
        j = 0;
        dia = 0;
        do
        {
            if (string[i] == '>' && j > 0 && limpo[j - 1] == '<')
            {
                dia++;
                j--;
            }
            else if (string[i] != '.')
            {
                limpo[j] = string[i];
                j++;
            }
            i++;
        } while (string[i] != '\0');
        printf("%d\n", dia);
    }
    return 0;
}