#include "logger.h"
#include "alg.h"

void isort(int *, int);

int main()
{

  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print_array(array, 10);
  start_clock();
  isort(array, 10);
  end_clock();
  print_array(array, 10);
  diff_time();

  return 0;
}

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
