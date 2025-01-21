#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pilha[50], descarte[50], transf, j, resto; 
    do {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            pilha[i] = i + 1;
        }
        j = 0;
        resto = n;
        while (resto > 1) {
            descarte[j] = pilha[0];
            j++;
            transf = pilha[1];
            for (int k = 0; k < resto - 2; k++) {
                pilha[k] = pilha[k + 2];
            }
            pilha[resto - 2] = transf;
            resto--;
        }
        printf("Discarded cards: ");
        for (int i = 0; i < j; i++) {
            printf("%d", descarte[i]);
            if (i < j - 1) printf(", ");
        }
        printf("\nRemaining card: %d\n", pilha[0]);
    } while (1);
    return 0;
}