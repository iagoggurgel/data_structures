#include "alg.h"

/*
  Algoritmo de ordenação Insertion Sort

  Entradas:
      v: ponteiro para um vetor de inteiros
      n: número de elementos do vetor v

*/
void iSort(int * v, int n)
{
  int j, i;
  i = 1;
  while(i < n)
  {
    j = i;
    while(j > 0 && v[j - 1] > v[j])
    {
      swap(&v[j - 1], &v[j]);
      j -= 1;
    }
    i += 1;
  }
}

/*
  Função para realizar os testes do algoritmo de ordenação Insertion Sort
*/
void testInsertionSort()
{
    
    int * inputArray = generateInputArray();

    int * subArray;

    FILE * fp = fopen("results/insertionSort.csv", "w");

    fprintf(fp, "n,t\n");

    for (int i = 0; i < (TESTCASES >> 2); i++)
    {
        int numberOfInputs = ((((GROWTHRATE >> 2) * i) + 1) % 65536);

        subArray = generateSubArray(inputArray, numberOfInputs);

        startClock();
        iSort(subArray, numberOfInputs);
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