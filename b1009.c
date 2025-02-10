#include <stdio.h>

int main()
{
    float a, b, total;
    char nome[100];
    scanf("%s", nome);
    scanf("%f %f", &a, &b);
    total = a + (0.15 * b);
    printf("TOTAL = %.2f\n", total);
}