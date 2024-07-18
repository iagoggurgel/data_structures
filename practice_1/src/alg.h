#ifndef ALG_H
#define ALG_H


#include <stdlib.h>
#include "utils.h"

void iSort(int *, int);
void sSort(int *, int);
void qSort(int *, int, int);
void mSort(int *, int, int);
void dSort(int *, int, int);
// void cSort(int * v, int); Needs fixing
void hSort(int *, int);

/*
    Future algorithms I want to cover

    Sorts:
        Radix Sort
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
