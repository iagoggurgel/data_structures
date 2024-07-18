#include "alg.h"

struct node_h
{

    int value;
    struct node_h * next;

};


void insertHead(struct node_h **, int);
void insertEnd(struct node_h **, int);
void lSort(struct node_h *);


/*
    Algoritmo de ordenação Distribution Sort (Bucket Sort)

    Entradas:
        v: vetor de inteiros
        n: número de elementos de v

*/
void dSort(int * v, int n, int k)
{
    struct node_h * buckets = (struct node_h *) calloc(k, sizeof(struct node_h));
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
void insertNumber(struct node_h ** head_ref, int x)
{
    struct node_h * newNumber = (struct node_h *) malloc(sizeof(struct node_h));
    newNumber->value = x;
    newNumber->next = NULL;
    struct node_h * aux = head_ref;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = newNumber;
}

/*
    Algoritmo de ordenação de listas encadeadas baseado no Insertion Sort

    Entradas:
        v: lista encadeada
        k: número de elementos de v

*/
void lSort(struct node_h * v)
{
    struct node_h * i, * j, * aux;

    i = v->next;
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