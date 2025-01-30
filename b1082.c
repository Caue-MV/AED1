#include <stdio.h>

#define MAX 26

int grafo[MAX][MAX];
int visitado[MAX];
int V;

void limpaGrafo()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            grafo[i][j] = 0;
        }
    }
    for (int i = 0; i < MAX; i++)
    {
        visitado[i] = 0;
    }
}

void dfs(int v)
{
    visitado[v] = 1;
    printf("%c", v + 'a');
    for (int i = 0; i < V; i++)
    {
        if (grafo[v][i] == 1 && !visitado[i])
        {
            printf(",");
            dfs(i);
        }
    }
}

int main()
{
    int N, E;
    char v1, v2;
    scanf("%d", &N);
    for (int caso = 1; caso <= N; caso++)
    {
        limpaGrafo();
        scanf("%d %d", &V, &E);
        for (int i = 0; i < E; i++)
        {
            scanf(" %c %c", &v1, &v2);
            grafo[v1 - 'a'][v2 - 'a'] = 1;
            grafo[v2 - 'a'][v1 - 'a'] = 1;
        }
        printf("Case #%d:\n", caso);
        int componentes = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visitado[i])
            {
                dfs(i);
                printf(",\n");
                componentes++;
            }
        }
        printf("%d connected components\n\n", componentes);
    }
    return 0;
}