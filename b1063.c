#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    char entrada[30], saida[30], movimento[60];
    while (1)
    {
        scanf("%d", &N);
        if (N == 0)
            break;
        for (int i = 0; i < N; i++)
            scanf(" %c", &entrada[i]);
        for (int i = 0; i < N; i++)
            scanf(" %c", &saida[i]);
        int pos_entrada = 0, pos_saida = 0, pos_movimento = 0;
        char pilha[30];
        int topo = -1;
        int impossivel = 0;
        while (pos_saida < N)
        {
            if (topo >= 0 && pilha[topo] == saida[pos_saida])
            {
                movimento[pos_movimento++] = 'R';
                topo--;
                pos_saida++;
            }
            else if (pos_entrada < N)
            {
                movimento[pos_movimento++] = 'I';
                pilha[++topo] = entrada[pos_entrada++];
            }
            else
            {
                impossivel = 1;
                break;
            }
        }
        movimento[pos_movimento] = '\0';
        if (impossivel)
        {
            for (int i = 0; i < pos_movimento; i++)
            {
                printf("%c", movimento[i]);
            }
            printf(" Impossible");
            printf("\n");
        }
        else
        {
            printf("%s\n", movimento);
        }
    }
    return 0;
}