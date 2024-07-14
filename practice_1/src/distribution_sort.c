#include <alg.h>


typedef
struct list
{

    int value;
    List * next;

} List;


/*
    Algoritmo de ordenação Distribution Sort (Bucket Sort)

    Entradas:
        v: vetor de inteiros
        n: número de elementos de v

*/
void dSort(int * v, int n)
{
    List buckets[n];
    int m = 1 + max(v, n);
    for (int i = 0; i < n; i++)
    {
        
    }
    
}

