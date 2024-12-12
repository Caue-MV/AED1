#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int p = arr[low];
    int i = low;
    int j = high;
    
    while (i < j) {
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }
        
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int max;
    clock_t t;
    srand((unsigned)time(NULL));

    for (max = 10000; max <= 500000; max = max + 10000)
    {
        int *arr = malloc(max * sizeof(int));
        if (!arr) {
            printf("Memory allocation failed\n");
            return 1;
        }

        for (int i = 0; i < max; i++) {
            arr[i] = rand() % max;
        }

        t = clock();
        quickSort(arr, 0, max - 1);
        t = clock() - t;

        printf("Tempo: %.0lf / Tamanho do array: %d\n", 
               ((double)t) / ((CLOCKS_PER_SEC / 1000)), 
               max);

        free(arr);
    }

    return 0;
}