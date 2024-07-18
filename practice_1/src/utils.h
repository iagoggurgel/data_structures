#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include <stdio.h>
#include "alg.h"
#include "input.h"
#define clear() system("clear || cls")
#define BOLD "\e[1m"
#define RESET "\e[m"

void diffTime();
void startClock();
void endClock();
void help();


#endif
