#include <stdio.h>
#include <string.h>

struct Produto
{
    char nome[51];
    double preco;
};

int main()
{
    int N, M, P;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &M);
        struct Produto produtos[M];
        for (int i = 0; i < M; i++)
        {
            scanf("%s %lf", produtos[i].nome, &produtos[i].preco);
        }
        scanf("%d", &P);
        double total = 0.0;
        for (int i = 0; i < P; i++)
        {
            char nome[51];
            int quantidade;
            scanf("%s %d", nome, &quantidade);
            for (int j = 0; j < M; j++)
            {
                if (strcmp(nome, produtos[j].nome) == 0)
                {
                    total += produtos[j].preco * quantidade;
                    break;
                }
            }
        }
        printf("R$ %.2f\n", total);
    }
    return 0;
}