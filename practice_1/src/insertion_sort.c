#include "utils.h"
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
