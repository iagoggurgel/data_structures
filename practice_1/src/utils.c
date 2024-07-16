#include "utils.h"
#include "alg.h"

struct timespec before;
struct timespec after;


/*
  Função auxiliar que printa a diferença do tempo inicial e tempo final.
*/
void diffTime()
{
  printf("%ld.%ld\n", after.tv_sec - before.tv_sec ,after.tv_nsec - before.tv_nsec);
}

/*
  Função auxiliar que pega o tempo de início do algoritmo de ordenação.
*/
void startClock()
{
  timespec_get(&before, TIME_UTC);
}


/*
  Função auxiliar que pega o tempo final do algoritmo de ordenação
*/
void endClock()
{
  timespec_get(&after, TIME_UTC);
}


/*
  Função auxiliar que troca os valores de a e b.
  
  Entradas:
    a: ponteiro para um número
    b: ponteiro para um número

  Funcionalidade:
    a -> b
    b -> a
    Utiliza o método de swap com a lógica de Exclusive-OR
*/
void swap(int * a, int * b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

/*
  Função auxiliar que escreve o array para STDOUT

  Entradas:
    v: ponteiro para um vetor de inteiros
    n: número de elementos do vetor v
*/
void printArray(int * v, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");
}


/*
  Função auxiliar para garantir que o vetor está ordenado

  Entradas:
    v: ponteiro para um vetor de inteiros
    n: número de elementos do vetor v
*/
int isSorted(int * v, int n)
{
  int i;
  for (i = 0; i < n - 1; i++)
  {
    if (v[i] > v[n + 1])
      goto notSorted;
  }

  return 0;

  notSorted: return -1;
}

/*
  Função auxiliar para achar o maior valor do vetor.

  Entradas:
    v: ponteiro para um vetor de inteiros
    n: número de elementos do vetor v
*/
int max(int * v, int n)
{
  int max = v[0];
  for (int i = 1; i < n; i++)
  {
    if (max < v[i])
    {
      max = v[i];
    }
  }
  return max;
}