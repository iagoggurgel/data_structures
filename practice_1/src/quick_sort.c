#include "alg.h"


/*
    Algoritmo de ordenação Quick Sort

    Entradas:
        v: vetor de inteiros
        s: primeiro elemento
        e: último elemento

*/
void qSort(int * v, int s, int e)
{
    if (s >= 0 && e >= 0 && s < e)
    {
        int p = partition(v, s, e);
        qSort(v, s, p);
        qSort(v, p + 1, e);
    }
}

int partition(int * v, int s, int e)
{

    int pivot = v[s];

    int i = s - 1;
    int j = e + 1;

    while (1)
    {
        do
        {
            i += 1;
        } while (v[i] < pivot);

        do
        {
            j -= 1;
        } while (v[j] > pivot);
        
        if (i >= j)
        {
            return j;
        }

        swap(v[i], v[j]);
    }
}