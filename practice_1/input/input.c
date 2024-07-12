#include "input.h"



int * generateInput()
{
    int * inputArray = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        inputArray[i] = rand();
    }

    return inputArray;
}

int * readInputs(const int x)
{
    int * inputArray = (int *) malloc(sizeof(int) * x);

    int * fileArray = (int *) malloc(sizeof(int) * n);
    
    FILE * fp = fopen("input.in", "w");

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d\n", &fileArray[i]);
    }

    fclose(fp);

    int randomStart = rand() % n;
    printf("%d", randomStart);

    exit(0);

    for (int i = 0; i < x; i++)
    {
        inputArray[i] = fileArray[randomStart];
        randomStart += (randomStart + 1) % n;
    }

    return inputArray;

}

void writeInputs()
{
    int * input;

    FILE * fp = fopen("input.in", "w");

    input = generateInput();

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", input[i]);
    }

    fclose(fp); 
}

void help()
{
    printf("This is a module for generating test cases for the algorithms\n");
    printf("Options for this module are:\n");
    printf("   -h / prints this help;\n");
    printf("   -w / write N_INPUT number of inputs to a file input.in;\n");
    printf("   -g / generates inputs, useful for measuring time;\n");
    printf("   -r / reads inputs and mounts an array for algorithm testing;\n");
    printf("\n");
}

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        return EXIT_FAILURE;
    }

    if(!strcmp(argv[1], "-w"))
    {
        writeInputs();
        return EXIT_SUCCESS;
    }
    else if(!strcmp(argv[1], "-h"))
    {
        help();
    }
    else if(!strcmp(argv[1], "-g"))
    {
        generateInput();
    }
    else if(!strcmp(argv[1], "-r"))
    {
        readInputs(20000000);
    }
}