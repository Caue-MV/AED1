#include <stdio.h>

int main()
{
    int n, h;
    float s;
    scanf("%d %d %f", &n, &h, &s);
    printf("NUMBER = %d\nSALARY = U$ %.2f", n, h * s);
    return 0;
}