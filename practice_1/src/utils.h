#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "algorithms/alg.h"
#include "input/input.h"
#define clear() system("clear || cls")
#define BOLD "\e[1m"
#define RESET "\e[m"

void diffTime();
void startClock();
void endClock();
void help();


#endif
