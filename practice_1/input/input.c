#include <stdio.h>
#include "logger.h"
#include <stdlib.h>
#include <math.h>


int main(int argc, char * argv[])
{
  
  FILE * log_file = (FILE *) fopen("app.log", "w");

  if (argc < 2)
  {
    error("No arguments passed to main!", log_file, LOG_FILE | LOG_STD);
    exit(1);
  }

  int numberOfInputs, inputNumber;

  inputNumber = atoi(argv[1]);

  if (inputNumber < 0) {
    error("inputNumber must be bigger than zero!", log_file, LOG_FILE | LOG_STD);
    exit(1);
  }

  if (inputNumber <= 10) {
    numberOfInputs = inputNumber * 3;
  }

  if (inputNumber > 10 && inputNumber < 250){
    numberOfInputs = (int) (25 + inputNumber * log(inputNumber)); 
  }

  if (inputNumber >= 250 && inputNumber <= 500){
    numberOfInputs = 25000 * inputNumber;
  }

  printf("%d\n", numberOfInputs);
  success("Closing!",log_file, LOG_STD | LOG_FILE);

  return 0;
}
