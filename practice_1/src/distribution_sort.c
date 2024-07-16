#include "alg.h"

typedef
struct list_h
{

    int value;
    struct list_h * next;

} List;


void insertNumber(List *, int);
void lSort(List *);


/*
    Algoritmo de ordenação Distribution Sort (Bucket Sort)

    Entradas:
        v: vetor de inteiros
        n: número de elementos de v

*/
void dSort(int * v, int n, int k)
{
    List * buckets = (List *) calloc(k, sizeof(List));
    List * tmp;
    int m = 1 + max(v, n);
    for (int i = 0; i < n; i++)
    {
        int bucket = (k * v[i]) / m;
        insertNumber(&buckets[bucket], v[i]);
    }
    for (int i = 0; i < k; i++)
    {
        lSort(&buckets[i]);
    }
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        tmp = &buckets[i];
        while (tmp->next != NULL)
        {
            printf("%d", tmp->value);
            v[j] = tmp->value;
            tmp = tmp->next;
            j++;
        }
    }
}

/*
    Função auxiliar para inserção de números na lista

    Entradas:
        v: vetor de inteiros
        n: número de elementos de v

*/
void insertNumber(List * prev, int x)
{
    List * newNumber = (List *) malloc(sizeof(List));
    newNumber->value = x;
    newNumber->next = NULL;
    List * aux = prev;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    if (aux == prev)
    {
        aux->value = x;
        free(newNumber);
        return;
    }
    aux->next = newNumber;
}

/*
    Algoritmo de ordenação de listas encadeadas baseado no Insertion Sort

    Entradas:
        v: lista encadeada
        k: número de elementos de v

*/
void lSort(List * v)
{
    List * i, * j, * aux;

    i = v;
    while (i->next != NULL)
    {
        j = i;
        while (j->next != NULL)
        {
            aux = j->next;
            if (aux->value < j->value)
            {
                swap(&aux->value, &j->value);
            }
            j = j->next;
        }
        i = i->next;
    }
}

int main()
{
    int v[] = {9492, 0, 1, 60, 49, 45, 85, 1002};
    dSort(v, 8, 3);
    printArray(v, 8);
    return EXIT_SUCCESS;
}