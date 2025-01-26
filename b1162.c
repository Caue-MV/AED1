#include <stdio.h>

int bubble(int arr[], int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}

int main() {
    int N, L;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &L);
        int vagoes[L];
        for (int i = 0; i < L; i++) {
            scanf("%d", &vagoes[i]);
        }
        int trocas = bubble(vagoes, L);
        printf("Optimal train swapping takes %d swaps.\n", trocas);
    }
    return 0;
}