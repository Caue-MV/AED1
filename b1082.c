#include <stdio.h>
#include <stdlib.h>

#define max 26

void bfs(int adj[max][max], int V, int s, int connected[max])
{
    int q[max], front = 0, rear = 0;
    int visited[max] = {0};
    visited[s] = 1;
    q[rear++] = s;
    while (front < rear)
    {
        int curr = q[front++];
        connected[curr] = 1;
        for (int i = 0; i < V; i++)
        {
            if (adj[curr][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
}

int main()
{
    int n, v, e, conectados;
    int grafo[max][max];
    int connected[max], passou[max];
    char inicio, fim;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        conectados = 0;
        for (int j = 0; j < max; j++)
        {
            passou[j] = 0;
            connected[j] = 0;
            for (int k = 0; k < max; k++)
            {
                grafo[j][k] = 0;
            }
        }
        scanf("%d %d", &v, &e);
        for (int j = 0; j < e; j++)
        {
            scanf(" %c %c", &inicio, &fim);
            grafo[(int)inicio - 97][(int)fim - 97] = 1;
            grafo[(int)fim - 97][(int)inicio - 97] = 1;
        }
        printf("Case #%d:\n", i+1);
        for (int j = 0; j < v; j++)
        {
            if (connected[j] == 0 && passou[j] == 0)
            {
                bfs(grafo, v, j, connected);
                conectados++;
                for (int k = 0; k < v; k++)
                {
                    if (connected[k] == 1 && passou[k] == 0)
                    {
                        passou[k] = 1;
                        printf("%c,", (char)(k + 97));
                    }
                }
                printf("\n");
            }
        }
        printf("%d connected components\n\n", conectados);
    }
    return 0;
}