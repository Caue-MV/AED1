#include <stdio.h>

int main(){
    int a, b;
    float c, item1, item2;
    scanf("%d %d %f", &a, &b, &c);
    item1 = b * c;
    scanf("%d %d %f", &a, &b, &c);
    item2 = b * c;
    printf("VALOR A PAGAR: R$ %.2f\n", item1+item2);
    return 0;
}