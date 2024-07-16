#include "alg.h"



/*
    Algoritmo de ordenação Selection Sort

    Entradas:
        v: ponteiro para um vetor de inteiros
        n: número de elementos do vetor v

*/
void sSort(int * v, int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; i < n; i++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap(v[i], v[min]);
        }
    }
}