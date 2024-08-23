#ifndef INPUT_H
#define INPUT_H 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int * generateInputArray();
int * generateSubArray(int *, int);

static const int input_n = 1048576; // Allocates exactly 4MB of memory for a random list of integers.

#endif