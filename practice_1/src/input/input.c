#include "input.h"


/*
    Algoritmo de geração de um Array de inteiros pseudo-aleatórios.

    Observação:
        Por padrão, aloca um Array de 1048576 posições, portanto, em um computador comum, onde o inteiro equivale a 4 bytes,
        aloca 4MB de memória.
*/
int * generateInputArray()
{
    int * inputArray = (int *) malloc(sizeof(int) * input_n); // Allocates exactly 4MB of memory for a random list of integers.

    if (inputArray == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < input_n; i++)
    {
        inputArray[i] = rand();
    }

    return inputArray;
}


/*
    Algoritmo de geração de SubArray de inteiros pseudo-aleatórios baseados no Array geral.

    Entradas:
        n: número de posições do SubArray
        inputArray: Array de inteiros pseudo-aleatórios gerado por generateInputArray
*/
int * generateSubArray(int n, int * inputArray)
{
    int * inputSubArray = (int *) malloc(sizeof(int) * n);
    int arrayPos;
    srand(time(NULL));
    if (inputSubArray == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        arrayPos = rand() % input_n;
        printf("%d\n", arrayPos);
        inputSubArray[i] = inputArray[arrayPos];
    }

    return inputSubArray;
}
