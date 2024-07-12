#include "utils.h"
#include "alg.h"

struct timespec before;
struct timespec after;

void diffTime()
{
  printf("%ld.%ld\n", after.tv_sec - before.tv_sec ,after.tv_nsec - before.tv_nsec);
}

void startClock()
{
  timespec_get(&before, TIME_UTC);
}

void endClock()
{
  timespec_get(&after, TIME_UTC);
}

void swap(int * a, int * b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void printArray(int * a, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int isSorted(int * a, int n)
{
  int i;
  for (i = 0; i < n - 1; i++)
  {
    if (a[i] > a[n + 1])
      goto notSorted;
  }

  return 0;

  notSorted: return -1;
}