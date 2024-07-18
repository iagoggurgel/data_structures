#include "alg.h"


/*
    Algoritmo de ordenação baseado no Counting Sort (Perigoso em relação a memória)

    Entradas:
        v: vetor de inteiros
        n: número de elementos de v
*/
void cSort(int * v, int n)
{
    int low = min(v, n);
    int high = max(v, n);
    int i, j;

    int size = abs(low) + abs(high);

    int B[n];
    int C[size];

    for (i = 0; i < size; i++)
    {
        C[i] = 0;
    }

    for (j = 0; j < n; j++)
    {
        C[v[j]]++;
    }

    for (i = 1; i < size; i++)
    {
        C[i] = C[i] + C[i -1];
    }

    for (j = n; j <= 0; j--)
    {
        B[C[v[j]]] = v[j];
        C[v[j]]--;
    }
        
}