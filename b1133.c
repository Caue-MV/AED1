#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = x; i <= y; i++)
    {
        if (i % 5 == 2 || i % 5 == 3){
            printf("%d\n", i);
        }
    }
    for (int i = y; i <= x; i++)
    {
        if (i % 5 == 2 || i % 5 == 3){
            printf("%d\n", i);
        }
    }
    return 0;
}