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
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap(&v[i], &v[min]);
        }
    }
}

/*
  Função para realizar os testes do algoritmo de ordenação Selection Sort
*/
void testSelectionSort()
{
    
    int * inputArray = generateInputArray();

    int * subArray;

    FILE * fp = fopen("results/selectionSort.csv", "w");

    fprintf(fp, "n,t\n");

    for (int i = 0; i < (TESTCASES >> 2); i++)
    {
        int numberOfInputs = ((((GROWTHRATE >> 2) * i) + 1) % 65536);

        subArray = generateSubArray(inputArray, numberOfInputs);

        startClock();
        sSort(subArray, numberOfInputs);
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