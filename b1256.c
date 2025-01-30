#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h[100][200], x, m, n, c, preenchido;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 200; k++)
            {
                h[j][k] = 0;
            }
        }
        scanf("%d", &m);
        scanf("%d", &c);
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &x);
            preenchido = 0;
            while (h[x % m][preenchido] != 0)
            {
                preenchido++;
            }
            h[x % m][preenchido] = x;
        }
        for (int j = 0; j < m; j++)
        {
            printf("%d -> ", j);
            preenchido = 0;
            while (h[j][preenchido] != 0)
            {
                printf("%d -> ", h[j][preenchido]);
                preenchido++;
            }
            printf("\\\n");
        }
        if (i < n - 1)
        {
            printf("\n");
        }
    }
    return 0;
}