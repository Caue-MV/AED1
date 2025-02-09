#include <stdio.h>

int main()
{
    float n1, n2, n3, n4, exame;
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
    printf("Media: %.1f\n", (2 * n1 + 3 * n2 + 4 * n3 + n4) / 10);
    if ((2 * n1 + 3 * n2 + 4 * n3 + n4) / 10 >= 7)
    {
        printf("Aluno aprovado.\n");
    }
    else if ((2 * n1 + 3 * n2 + 4 * n3 + n4) / 10 < 5)
    {
        printf("Aluno reprovado.\n");
    }
    else
    {
        printf("Aluno em exame.\n");
        scanf("%f", &exame);
        printf("Nota do exame: %.1f\n", exame);
        if (((2 * n1 + 3 * n2 + 4 * n3 + n4) / 10 + exame) / 2 > 5)
        {
            printf("Aluno aprovado.\n");
        }
        else
        {
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1f\n", ((2 * n1 + 3 * n2 + 4 * n3 + n4) / 10 + exame)/2);
    }
    return 0;
}