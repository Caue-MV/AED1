#include <stdio.h>

int main(){
    int dia, mes, ano, input;
    scanf("%d", &input);
    ano = input / 365;
    mes = (input % 365) / 30;
    dia = (input % 365) % 30;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dia);
    return 0;
}