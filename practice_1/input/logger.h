#ifndef LOG_H
#define LOG_H

#define LOG_STD 0x0001
#define LOG_FILE 0x0002
#define UTCTOGMT3 10800
#define RESET "\033[0m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"

#include <stdio.h>
#include <time.h>

void info(char *, FILE *, int);
void success(char *, FILE *, int);
void error(char *, FILE *, int);

#endif


