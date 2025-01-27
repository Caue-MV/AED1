#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOME 100
#define MAX_CAMISETAS 60

typedef struct
{
    char nome[MAX_NOME];
    char cor[10];
    char tamanho;
} Camiseta;

int comparaCamisetas(const void *a, const void *b)
{
    Camiseta *c1 = (Camiseta *)a;
    Camiseta *c2 = (Camiseta *)b;
    int comp_cor = strcmp(c1->cor, c2->cor);
    if (comp_cor != 0)
        return comp_cor;
    if (c1->tamanho != c2->tamanho)
        return c2->tamanho - c1->tamanho;
    return strcmp(c1->nome, c2->nome);
}

int main()
{
    int N;
    Camiseta camisetas[MAX_CAMISETAS];
    int primeiro_caso = 1;

    while (1)
    {
        scanf("%d", &N);
        if (N == 0)
            break;
        getchar();
        for (int i = 0; i < N; i++)
        {
            fgets(camisetas[i].nome, MAX_NOME, stdin);
            camisetas[i].nome[strcspn(camisetas[i].nome, "\n")] = 0;
            char cor[10];
            char tamanho;
            scanf("%s %c", cor, &tamanho);
            getchar();
            strcpy(camisetas[i].cor, cor);
            camisetas[i].tamanho = tamanho;
        }
        qsort(camisetas, N, sizeof(Camiseta), comparaCamisetas);
        if (!primeiro_caso)
        {
            printf("\n");
        }
        primeiro_caso = 0;
        for (int i = 0; i < N; i++)
        {
            printf("%s %c %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
        }
    }
    return 0;
}