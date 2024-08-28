#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "algorithms/alg.h"
#define clear() system("clear || cls")
#define BOLD "\e[1m"
#define RESET "\e[m"

#define TESTCASES 8192
#define GROWTHRATE 128

void diffTime(FILE *, int);
void startClock();
void endClock();

#endif
