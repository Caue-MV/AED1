#include <stdio.h>

int main()
{
    int n, conv;
    scanf("%d", &n);
    printf("%d\n", n);
    conv = n / 100;
    printf("%d nota(s) de R$ 100,00\n", conv);
    n -= conv * 100;
    conv = n / 50;
    printf("%d nota(s) de R$ 50,00\n", conv);
    n -= conv * 50;
    conv = n/20;
    printf("%d nota(s) de R$ 20,00\n", conv);
    n -= conv*20;
    conv = n/10;
    printf("%d nota(s) de R$ 10,00\n", conv);
    n -= conv*10;
    conv = n/5;
    printf("%d nota(s) de R$ 5,00\n", conv);
    n -= conv*5;
    conv = n/2;
    printf("%d nota(s) de R$ 2,00\n", conv);
    n -= conv*2;
    printf("%d nota(s) de R$ 1,00\n", n);
    return 0;
}