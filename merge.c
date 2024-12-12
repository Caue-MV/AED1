#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (!L || !R)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int max = 10000;
    clock_t t;
    srand((unsigned)time(NULL));
    for (max = 10000; max <= 500000; max = max + 10000)
    {
        int *vet = malloc(max * sizeof(int));
        if (!vet)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        for (int i = 0; i < max; i++)
        {
            vet[i] = rand() % max;
        }
        
        t = clock();
        mergeSort(vet, 0, max - 1);
        t = clock() - t;
        printf("Tempo: %.0lf / Tamanho do array: %d\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)), max);

        free(vet);
    }
    return 0;
}