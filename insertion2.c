#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void insertion(int *vet, int max)
{
    int i, j, key;
    for (i = 1; i < max; i++)
    {
        key = vet[i];
        j = i - 1;
        
        while (j >= 0 && vet[j] > key)
        {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = key;
    }
}

int main()
{
    int max;
    clock_t t;
    srand((unsigned)time(NULL));


    for (max = 10000; max <= 150000; max = max + 10000)
    {
        int *vet = malloc(max * sizeof(int));
        if (!vet) {
            printf("Memory allocation failed\n");
            return 1;
        }

        for (int i = 0; i < max; i++)
        {
            vet[i] = rand() % max;
        }

        t = clock();
        insertion(vet, max);
        t = clock() - t;

        printf("Tempo: %.0lf / Tamanho do array: %d\n", 
               ((double)t) / ((CLOCKS_PER_SEC / 1000)), 
               max);

        free(vet);
    }
    return 0;
}