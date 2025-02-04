#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int p = arr[low];
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

void quickSort(int *arr, int low, int high)
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
    int n, pares[100000], impares[100000], input, j = 0, k = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        if (input % 2 == 0)
        {
            pares[j] = input;
            j++;
        }
        else
        {
            impares[k] = input;
            k++;
        }
    }
    quickSort(pares, 0, j - 1);
    quickSort(impares, 0, k - 1);
    for (int i = 0; i < j; i++)
    {
        printf("%d\n", pares[i]);
    }
    for (int i = k - 1; i >= 0; i--)
    {
        printf("%d\n", impares[i]);
    }
    return 0;
}