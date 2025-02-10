#include <stdio.h>
#include <stdlib.h>

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

int partition(float *arr, int low, int high)
{
    float p = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= p && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > p && j >= low + 1)
        {
            j--;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(float *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    float valores[3];
    scanf("%f %f %f", &valores[0], &valores[1], &valores[2]);
    quickSort(valores, 0, 2);
    printf("%f %f %f", valores[0], valores[1], valores[2]);
    if (valores[3] >= valores[2] + valores[1])
    {
        printf("NAO FORMA TRIANGULO\n");
    }
    else
    {
        if ((valores[2] * valores[2]) == (valores[1] * valores[1] + valores[0] * valores[0]))
        {
            printf("TRIANGULO RETANGULO\n");
        }
        if ((valores[2] * valores[2]) > (valores[1] * valores[1] + valores[0] * valores[0]))
        {
            printf("TRIANGULO OBTUSANGULO\n");
        }
        if ((valores[2] * valores[2]) < (valores[1] * valores[1] + valores[0] * valores[0]))
        {
            printf("TRIANGULO ACUTANGULO\n");
        }
        if (valores[2] == valores[1] || valores[2] == valores[0] || valores[1] == valores[0])
        {
            if (valores[2] == valores[1] && valores[2] == valores[0])
            {
                printf("TRIANGULO EQUILATERO\n");
            }
            else
            {
                printf("TRIANGULO ISOSCELES\n");
            }
        }
    }
    return 0;
}