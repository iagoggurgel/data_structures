#include "alg.h"

int partition(int *, int, int);


/*
    Algoritmo de ordenação Quick Sort

    Entradas:
        v: vetor de inteiros
        s: índice inicial
        e: índice final

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

/*
    Função auxiliar para partir e ordenar os sub-vetores utilizados no Quick Sort

    Entradas:
        v: vetor de inteiros
        s: índice inicial
        e: índice final
*/
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

        swap(&v[i], &v[j]);
    }
}

/*
  Função para realizar os testes do algoritmo de ordenação Quick Sort
*/
void testQuickSort()
{
    
    int * inputArray = generateInputArray();

    int * subArray;

    FILE * fp = fopen("results/quickSort.csv", "w");

    fprintf(fp, "n,t\n");

    for (int i = 0; i < TESTCASES; i++)
    {
        int numberOfInputs = (((GROWTHRATE * i) + 1) % input_n);

        subArray = generateSubArray(inputArray, numberOfInputs);

        startClock();
        qSort(subArray, 0, numberOfInputs - 1);
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