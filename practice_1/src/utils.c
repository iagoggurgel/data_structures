#include "logger.h"
#include "alg.h"

struct timespec before;
struct timespec after;

void diff_time()
{
  printf("%ld.%ld\n", after.tv_sec - before.tv_sec ,after.tv_nsec - before.tv_nsec);
}

void start_clock()
{
  timespec_get(&before, TIME_UTC);
}

void end_clock()
{
  timespec_get(&after, TIME_UTC);
}

void swap(int * a, int * b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void print_array(int * a, int n)
{
  int i;
  for(i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

