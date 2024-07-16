#ifndef ALG_H
#define ALG_H


#include <stdlib.h>
#include "utils.h"

void iSort(int *, int);
void sSort(int *, int);
void qSort(int *, int, int);
void mSort(int *, int);
void dSort(int *, int, int);

void swap(int *, int *);
void printArray(int *, int);
int isSorted(int *, int);
int max(int *, int);

#endif
