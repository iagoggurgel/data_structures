#ifndef INPUT_H
#define INPUT_H 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int * generateInputArray();
int * generateSubArray(int, int *);

// 1048576
static const int input_n = 262144; // Allocates exactly 1MB of memory for a random list of integers.

#endif