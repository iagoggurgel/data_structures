#include "logger.h"
#include "alg.h"

void isort(int * a, int n)
{
  int j, i;
  i = 1;
  while(i < n)
  {
    j = i;
    while(j > 0 && a[j - 1] > a[j])
    {
      swap(&a[j - 1], &a[j]);
      j -= 1;
    }
    i += 1;
  }
}
