#ifndef UTILS_H
#define UTILS_H

#include <time.h>
#include <stdio.h>
<<<<<<< HEAD
#include <string.h>
#include "alg.h"
#include "input.h"
=======
#include <unistd.h>
#include "algorithms/alg.h"
#include "input/input.h"
>>>>>>> 7bce2066329d43fd6ab19e28be89474302937fab
#define clear() system("clear || cls")
#define BOLD "\e[1m"
#define RESET "\e[m"

void diffTime();
void startClock();
void endClock();
void help();


#endif
