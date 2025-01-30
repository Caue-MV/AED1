#include <stdio.h>

#define MAX 1001

int pilha[MAX];
int topo;

void push(int x)
{
    pilha[++topo] = x;
}

int pop()
{
    return pilha[topo--];
}

int top()
{
    return pilha[topo];
}

int isEmpty()
{
    return topo == -1;
}

int verificaPermutacao(int n, int perm[])
{
    int proximo = 1;
    topo = -1;
    for (int i = 0; i < n; i++)
    {
        while (proximo <= n && (isEmpty() || top() != perm[i]))
        {
            push(proximo++);
        }
        if (isEmpty() || top() != perm[i])
        {
            return 0;
        }
        pop();
    }
    return 1;
}

int main()
{
    int n, perm[MAX];
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        while (1)
        {
            scanf("%d", &perm[0]);
            if (perm[0] == 0)
            {
                printf("\n");
                break;
            }
            for (int i = 1; i < n; i++)
            {
                scanf("%d", &perm[i]);
            }
            if (verificaPermutacao(n, perm))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}