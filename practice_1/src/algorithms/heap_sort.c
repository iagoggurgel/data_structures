#include "alg.h"

void heapify(int *, int, int);


/*
    Algoritmo de ordenação Heap Sort

    Entradas:
        v: vetor de inteiros
        n: número de elementos de v
*/
void hSort(int * v, int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(v, n, i);
    }

    // Heap sort
    for (int i = n - 1; i > 0; i--) {

        swap(&v[0], &v[i]);

        heapify(v, i, 0);
    }
}


/*
    Função auxiliar para realizar o Heapify no vetor v.

    Entradas:
        v: vetor de inteiros
        n: tamanho da heap
        i: "nó" da heap (índice do vetor v)
*/
void heapify(int * v, int n, int i)
{

    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < n && v[left] > v[largest])
    {
        largest = left;
    }

    if (right < n && v[right] > v[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&v[i], &v[largest]);

        heapify(v, n, largest);
    }
}

/*
  Função para realizar os testes do algoritmo de ordenação Heap Sort
*/
void testHeapSort()
{
    
    int * inputArray = generateInputArray();

    int * subArray;

    FILE * fp = fopen("results/heapSort.csv", "w");

    fprintf(fp, "n,t\n");

    for (int i = 0; i < TESTCASES; i++)
    {
        int numberOfInputs = (((GROWTHRATE * i) + 1) % input_n);

        subArray = generateSubArray(inputArray, numberOfInputs);

        startClock();
        hSort(subArray, numberOfInputs);
        endClock();

        if (!isSorted(subArray, numberOfInputs))
        {
            diffTime(fp, numberOfInputs);
        }
        else
        {
            printArray(subArray, numberOfInputs);
            exit(EXIT_FAILURE);
        }
        

        free(subArray);
    }

    fclose(fp);

    free(inputArray);

}