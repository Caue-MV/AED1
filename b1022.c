#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplificar_fracao(int numerador, int denominador, int *num_simp, int *den_simp) {
    if (numerador == 0) {
        denominador = 1;
        return;
    }
    int div = mdc(numerador, denominador);
    *num_simp = numerador / div;
    *den_simp = denominador / div;
}

void calcular_operacao(int n1, int d1, char op, int n2, int d2, int *res_num, int *res_den) {
    switch(op) {
        case '+':
            *res_num = n1 * d2 + n2 * d1;
            *res_den = d1 * d2;
            break;
        case '-':
            *res_num = n1 * d2 - n2 * d1;
            *res_den = d1 * d2;
            break;
        case '*':
            *res_num = n1 * n2;
            *res_den = d1 * d2;
            break;
        case '/':
            *res_num = n1 * d2;
            *res_den = n2 * d1;
            break;
    }
}

int main() {
    int N, n1, d1, n2, d2, res_num, res_den, num_simp=0, den_simp=0;
    char op;
    scanf("%d", &N);
    while (N--) {
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
        calcular_operacao(n1, d1, op, n2, d2, &res_num, &res_den);
        simplificar_fracao(res_num, res_den, &num_simp, &den_simp);
        printf("%d / %d = %d / %d\n", res_num, res_den, num_simp, den_simp);
    }
    return 0;
}