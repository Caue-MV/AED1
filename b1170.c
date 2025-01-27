#include <stdio.h>

int main()
{
    int n, dias;
    float c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &c);
        for (dias = 0; c > 1; dias++)
        {
            c /= 2;
        }
        printf("%d dias\n", dias);
    }
}