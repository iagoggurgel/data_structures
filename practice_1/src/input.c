#include "input.h"

int * generateInput()
{
    int * inputArray = (int *) malloc(sizeof(int) * input_n);

    for (int i = 0; i < input_n; i++)
    {
        inputArray[i] = rand();
    }

    return inputArray;
}
