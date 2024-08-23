#ifndef ALG_H
#define ALG_H


#include <stdlib.h>
#include "../utils.h"

void iSort(int *, int);
void sSort(int *, int);
void qSort(int *, int, int);
void mSort(int *, int, int);
// void dSort(int *, int, int); Is Malfunctioning
void cSort(unsigned char *, int);
void hSort(int *, int);

void testInsertionSort();
void testSelectionSort();
void testQuickSort();
void testMergeSort();
// void testDistributionSort();
void testCountingSort();
void testHeapSort();

// void quine(int *, int); Needs implementation

/*
    Future algorithms I want to cover

    Sorts:
        Parallel versions of Quick Sort and Merge Sort
    
    Compression:
        Huffman Coding
    
    Path finding:
        Dijkstra
        A*

    Other:
        Quine McCluskey Algorithm
        Longest Common Subsequence
*/

void swap(int *, int *);
void printArray(int *, int);
int isSorted(int *, int);
int max(int *, int);
int min(int *, int);

#endif
