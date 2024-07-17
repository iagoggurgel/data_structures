#include "alg.h"

struct node_h
{

    int value;
    struct node_h * next;

};

struct head_h
{
    struct node_h * tail;
};


void insertNumber(struct head_h **, int);
void lSort(struct head_h *);


/*
    Algoritmo de ordenação Distribution Sort (Bucket Sort)

    Entradas:
        v: vetor de inteiros
        n: número de elementos de v

*/
void dSort(int * v, int n, int k)
{
    struct head_h * buckets = (struct head_h *) calloc(k, sizeof(struct head_h));
    struct node_h * tmp;
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
    free(buckets);
}

/*
    Função auxiliar para inserção de números na lista

    Entradas:
        v: vetor de inteiros
        n: número de elementos de v

*/
void insertNumber(struct head_h ** head_ref, int x)
{
    struct node_h * newNumber = (struct node_h *) malloc(sizeof(struct node_h));
    newNumber->value = x;
    newNumber->next = NULL;
    struct head_h * aux = head_ref;
    while (aux->tail != NULL)
    {
        aux = aux->tail;
    }
    aux->tail = newNumber;
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
    dSort(v, 8, 4);
    printArray(v, 8);
    return EXIT_SUCCESS;
}