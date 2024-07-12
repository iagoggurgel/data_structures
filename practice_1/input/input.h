#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifndef N_INPUT
#define N_INPUT 50000000
#endif

int * generateInput();
void writeInputs();
int * readInputs(const int);
void help();

const int n = N_INPUT;

#endif