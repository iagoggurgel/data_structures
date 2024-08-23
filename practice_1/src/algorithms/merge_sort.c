#include "alg.h"

void merge(int *, int, int, int);

/*
    Função auxiliar para intercalar os sub-vetores.

    Entradas:
        v: vetor de inteiros
        l: índice esquerdo
        m: índice do meio
        r: índice direito

*/
void merge(int * v, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = v[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = v[m + 1 + j]; 
  
    i = 0; 
  
    j = 0; 
  
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            v[k] = L[i]; 
            i++; 
        } 
        else { 
            v[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        v[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        v[k] = R[j]; 
        j++; 
        k++; 
    } 
} 


/*
    Algoritmo de ordenação Merge Sort

    Entradas:
        v: vetor de inteiros
        l: índice esquerdo
        r: índice direito

*/
void mSort(int * v, int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
  
        mSort(v, l, m); 
        mSort(v, m + 1, r); 
  
        merge(v, l, m, r); 
    } 
} 


/*
  Função para realizar os testes do algoritmo de ordenação Merge Sort
*/
void testMergeSort()
{
    
    int * inputArray = generateInputArray();

    int * subArray;

    FILE * fp = fopen("results/mergeSort.csv", "w");

    fprintf(fp, "n,t\n");

    for (int i = 0; i < TESTCASES; i++)
    {
        int numberOfInputs = (((GROWTHRATE * i) + 1) % input_n);

        subArray = generateSubArray(inputArray, numberOfInputs);

        startClock();
        mSort(subArray, 0, numberOfInputs - 1);
        endClock();

        if (!isSorted(subArray, numberOfInputs))
        {
            diffTime(fp, numberOfInputs);
        }
        else
        {
            printArray(subArray, numberOfInputs);
            exit(EXIT_FAILURE);
        }
        

        free(subArray);
    }

    fclose(fp);

    free(inputArray);

}