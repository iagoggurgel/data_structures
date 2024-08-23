#include "utils.h"

struct timespec before;
struct timespec after;


/*
  Função auxiliar que printa a diferença do tempo inicial e tempo final.
*/
void diffTime(FILE * file, int n)
{
  long seconds, nanoseconds;
  double texec;

  seconds = after.tv_sec - before.tv_sec;
  nanoseconds = after.tv_nsec - before.tv_nsec;

  if (nanoseconds < 0) {
    seconds -= 1;
    nanoseconds += 1000000000;
  }

  texec = seconds + nanoseconds / 1e9;
  fprintf(file, "%d,%.9f\n", n , texec);
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

  Observação:
    É necessário tomar cuidado com a situação onde a e b apontam para o mesmo
    endereço de memória. Nesse caso, a seguinte situação ocorrerá:

    a = b = 0111
    a = 0111 XOR 0111 = 0000
    
    As seguintes instruções de Exclusive-OR não vão fazer diferença e o valor de
    a será zerado.
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
    printf("%d -> ", v[i]);
  }
  printf("END\n");
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
    if (v[i] > v[i + 1])
      // Se há v[i] maior que seu sucessor, o vetor não está ordenado.
      return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
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

/*
  Função auxiliar para achar o menor valor do vetor.

  Entradas:
    v: ponteiro para um vetor de inteiros
    n: número de elementos do vetor v
*/
int min(int * v, int n)
{
  int min = v[0];
  for (int i = 1; i < n; i++)
  {
    if (min > v[i])
    {
      min = v[i];
    }
  }
  return min;
}


/*
  Função para 

*/
int checkOpt(char * argv[])
{
    if(!strcmp("-H", argv[1]))
    {
        return 0;
    }
    else if(!strcmp("-M", argv[1]))
    {
        return 1;
    }
    else if(!strcmp("-S", argv[1]))
    {
        return 2;
    }
    else if(!strcmp("-I", argv[1]))
    {
        return 3;
    }
    else if(!strcmp("-D", argv[1]))
    {
        return -1;
    }
    else if(!strcmp("-Q", argv[1]))
    {
        return 5;
    }
    else if(!strcmp("-C", argv[1]))
    {
      return 6;
    }
    else if(!strcmp("-All", argv[1]))
    {
      return 7;
    }

    return -1;
}


void help()
{
    clear();
    printf("ALGORITHMS RESEARCH\n\n");
    printf("%sDESCRIPTION%s\n", BOLD, RESET);
    printf("\trun the program using at least one option for an algorithm. When the program\n\tfinishes, it will write to .csv file named by the algorithm.\n\n");
    printf("%sOPTIONS%s\n", BOLD, RESET);
    printf("\t-M %sMERGE SORT%s\n", BOLD, RESET);
    printf("\t\truns tests on Merge Sort Algorithm and writes results to 'results/mergeSort.csv'.\n\n");
    printf("\t-H %sHEAP SORT%s\n", BOLD, RESET);
    printf("\t\truns tests on Heap Sort Algorithm and writes results to 'results/heapSort.csv'.\n\n");
    printf("\t-S %sSELECTION SORT%s\n", BOLD, RESET);
    printf("\t\truns tests on Selection Sort Algorithm and writes results to 'results/selectionSort.csv'.\n\n");
    printf("\t-I %sINSERTION SORT%s\n", BOLD, RESET);
    printf("\t\truns tests on Insertion Sort Algorithm and writes results to 'results/insertionSort.csv'.\n\n");
    //printf("\t-D %sDISTRIBUTION SORT%s\n", BOLD, RESET);
    //printf("\t\truns tests on Distribution Sort Algorithm and writes results to 'results/distribution.csv'.\n\n");
    printf("\t-Q %sQUICK SORT%s\n", BOLD, RESET);
    printf("\t\truns tests on Quick Sort Algorithm and writes results to 'results/quickSort.csv'.\n\n");
    printf("\n\n\n\n");

    printf("\t-All %sRUNS ALL ALGORITHMS%s\n", BOLD, RESET);
    printf("\t\truns tests on all Algorithms and writes results to 'results/<algorithm>.csv'.\n\n");
}