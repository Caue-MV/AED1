#include <stdio.h>
#include <math.h>

#define max 49

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
    int t, n, v, a, inicio, fim, movimentos;
    int grafo[max][max], connected[max] = {0};
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        scanf("%d %d", &v, &a);
        for (int j = 0; j < max; j++)
        {
            for (int k = 0; k < max; k++)
            {
                grafo[j][k] = 0;
                grafo[j][k] = 0;
            }
        }
        for (int j = 0; j < a; j++)
        {
            scanf("%d %d", &inicio, &fim);
            grafo[inicio][fim] = 1;
            grafo[fim][inicio] = 1;
        }
        movimentos = 0;
        bfs(grafo, v, n, connected);
        for (int j = 0; j < v; j++)
        {
            for (int k = 0; k < v; k++)
            {
                if(grafo[j][k] == 1 && connected[j] == 1 && connected[k] == 1){
                    movimentos++;
                }
            }
        }
        printf("%d\n", movimentos);
    }
    return 0;
}