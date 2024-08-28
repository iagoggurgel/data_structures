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