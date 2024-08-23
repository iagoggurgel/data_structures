#include "alg.h"

unsigned char * generateInputArrayS();
unsigned char * generateSubArrayS(unsigned char *, int);
int isSortedS(unsigned char * v, int );
void printArrayS(unsigned char *, int);

/*
    Algoritmo de ordenação baseado no Counting Sort para arrays de UTF-8

    Entradas:
        v: vetor de characters
        n: número de elementos de v
*/
void cSort(unsigned char * v, int n)
{
    int i, j;

    int size = __UINT8_MAX__;

    unsigned char B[n];
    int C[size + 1];

    for (i = 0; i < size + 1; i++)
    {
        C[i] = 0;
    }

    for (j = 0; j < n; j++)
    {
        C[v[j]]++;
    }

    for (i = 1; i <= size; i++)
    {
        C[i] = C[i] + C[i - 1];
    }

    for (j = n - 1; j >= 0; j--)
    {
        B[C[v[j]] - 1] = v[j];
        C[v[j]]--;
    }

    for (i = 0; i < n; i++)
    {
        v[i] = B[i];
    }
    
}

/*
    Algoritmo de geração de um Array de chars pseudo-aleatórios.

    Observação:
        Por padrão, aloca um Array de 1048576 posições, portanto, em um computador comum, onde o char equivale a 1 byte,
        aloca 1MB de memória.
*/
unsigned char * generateInputArrayS()
{
    unsigned char * inputArray = (unsigned char *) malloc(sizeof(unsigned char) * input_n); // Allocates exactly 1MB of memory for a random list of chars.

    if (inputArray == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < input_n; i++)
    {
        inputArray[i] = rand() % __UINT8_MAX__;
    }

    return inputArray;
}


/*
    Algoritmo de geração de SubArray de chars pseudo-aleatórios baseados no Array geral.

    Entradas:
        inputArray: Array de chars pseudo-aleatórios gerado por generateInputArrayS
        n: número de posições do SubArray
*/
unsigned char * generateSubArrayS(unsigned char * inputArray, int n)
{
    unsigned char * inputSubArray = (unsigned char *) malloc(sizeof(unsigned char) * n);
    int arrayPos;
    srand(time(NULL));
    if (inputSubArray == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        arrayPos = rand() % input_n;
        inputSubArray[i] = inputArray[arrayPos];
    }

    return inputSubArray;
}

/*
  Função auxiliar para garantir que o vetor está ordenado

  Entradas:
    v: ponteiro para um vetor de chars
    n: número de elementos do vetor v
*/
int isSortedS(unsigned char * v, int n)
{
  int i;
  for (i = 0; i < n - 1; i++)
  {
    if (v[i] > v[i + 1])
      // Se há v[i] maior que seu sucessor, o vetor não está ordenado.
      goto notSorted;
  }

  return EXIT_SUCCESS;

  notSorted: return EXIT_FAILURE;
}

/*
  Função para realizar os testes do algoritmo de ordenação Counting Sort
*/
void testCountingSort()
{
    
    unsigned char * inputArray = generateInputArrayS();

    unsigned char * subArray;

    FILE * fp = fopen("results/countingSort.csv", "w");

    fprintf(fp, "n,t\n");

    for (int i = 0; i < TESTCASES; i++)
    {
        int numberOfInputs = (((GROWTHRATE * i) + 1) % input_n);

        subArray = generateSubArrayS(inputArray, numberOfInputs);

        startClock();
        cSort(subArray, numberOfInputs);
        endClock();

        if (!isSortedS(subArray, numberOfInputs))
        {
            diffTime(fp, numberOfInputs);
        }
        else
        {
            printArrayS(subArray, numberOfInputs);
            exit(EXIT_FAILURE);
        }
        

        free(subArray);
    }

    fclose(fp);

    free(inputArray);

}


/*
  Função auxiliar que escreve o array para STDOUT

  Entradas:
    v: ponteiro para um vetor de chars
    n: número de elementos do vetor v
*/
void printArrayS(unsigned char * v, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d -> ", v[i]);
  }
  printf("END\n\n\n");
}
