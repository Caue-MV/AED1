#include <stdio.h>
#include <stdlib.h>

int contar_alunos_estaticos(int *original, int *ordenado, int tamanho) {
    int estaticos = 0;
    for (int i = 0; i < tamanho; i++) {
        if (original[i] == ordenado[i]) {
            estaticos++;
        }
    }
    return estaticos;
}

int comparar(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N, M;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &M);
        int notas_original[M];
        int notas_ordenadas[M];
        for (int i = 0; i < M; i++) {
            scanf("%d", &notas_original[i]);
            notas_ordenadas[i] = notas_original[i];
        }
        qsort(notas_ordenadas, M, sizeof(int), comparar);
        int alunos_estaticos = contar_alunos_estaticos(notas_original, notas_ordenadas, M);
        printf("%d\n", alunos_estaticos);
    }
    return 0;
}