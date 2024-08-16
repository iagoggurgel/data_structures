#include "alg.h"

/*
    Estrutura de um nó da lista encadeada

    Atributos:
        data: valor de contido no nó
        next: ponteiro para o próximo nó da lista.
*/
struct node_h {
    int data;
    struct node_h * next;
};


void push(struct node_h **, int);
void lSort(struct node_h **);
void printNodes(struct node_h *);


/*
    Algoritmo de ordenação Distribution Sort (Bucket Sort)

    Entradas:
        v: vetor de inteiros
        n: número de elementos de v
        k: número de buckets

*/
void dSort(int * v, int n, int k)
{
    struct node_h ** buckets = (struct node_h **) calloc(k, sizeof(struct node_h *));
    struct node_h * tmp;
    int m = 1 + max(v, n);
    int bucket;
    for (int i = 0; i < n; i++)
    {
        bucket = (k * v[i]) / m;
        push(&buckets[bucket], v[i]);
    }
    for (int i = 0; i < k; i++)
    {
        lSort(&buckets[i]);
    }
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        tmp = buckets[i];
        if (tmp == NULL)
        {
            continue;
        }
        v[j] = tmp->data;
        j++;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            v[j] = tmp->data;
            j++;
        }
    }
    free(buckets);
}

/*
    Função auxiliar para inserção de números na lista

    Entradas:
        node: nó raiz da lista encadeada
        n: número de elementos de v

*/
void push(struct node_h ** node, int x) {
    
    struct node_h * newNode = (struct node_h *) malloc(sizeof(struct node_h));
    struct node_h * aux;
    newNode->data = x;
    newNode->next = NULL;
    if (*node == NULL)
    {
        *node = newNode;
        return;
    }

    aux = *node;

    while (aux->next != NULL)
    {
        aux = aux->next;
    }

    aux->next = newNode;
    return;
}

void printNodes(struct node_h * node)
{
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

/*
    Algoritmo de ordenação de listas encadeadas baseado no Insertion Sort

    Entradas:
        v: lista encadeada
        k: número de elementos de v

*/
void lSort(struct node_h ** node)
{
    struct node_h * i, * j, * aux;
    if (*node == NULL)
    {
        return;
    }
    
    i = *node;
    while (i->next != NULL)
    {
        j = i;
        while (j->next != NULL)
        {
            aux = j->next;
            if (aux->data < j->data)
            {
                swap(&aux->data, &j->data);
            }
            j = j->next;
        }
        i = i->next;
    }
}