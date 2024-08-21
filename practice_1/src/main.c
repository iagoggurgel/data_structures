#include "utils.h"

int main(int argc, char * argv[])
{

    const int testCases = 10000;
    
    if (argc != 2)
    {
        exit(EXIT_FAILURE);
    }
    
    switch (checkOpt(argv))
    {
    case 0:
        void (*sortingAlgorithm)(int *, int) = &hSort;
        break;
    
    case 1:
        void (*sortingAlgorithm)(int *, int, int) = &mSort;
        break;

    case 2:
        void (*sortingAlgorithm)(int *, int) = &sSort;
        break;

    case 3:
        void (*sortingAlgorithm)(int *, int) = &iSort;
        break;

    case 4:
        void (*sortingAlgorithm)(int *, int, int) = &dSort;
        break;

    case 5:
        void (*sortingAlgorithm)(int *, int, int) = &qSort;
        break;

    default:
        exit(EXIT_FAILURE);
    }

    int * inputArray = generateInputArray();

    sortingAlgorithm(inputArray, input_n);

    if( !isSorted(inputArray, input_n) )
    {
        printf("The array has been sorted correctly!");
    }
    else
    {
        printf("The array has not been sorted correctly!");
    }
    
    return EXIT_SUCCESS;
}

int checkOpt(char * argv[])
{
    if(!strcmp("-H", argv[1]))
    {
        return 0;
    }
    else if(!strcmp("-M", argv[1]))
    {
        return 1;
    }
    else if(!strcmp("-S", argv[1]))
    {
        return 2;
    }
    else if(!strcmp("-I", argv[1]))
    {
        return 3;
    }
    else if(!strcmp("-D", argv[1]))
    {
        return 4;
    }
    else if(!strcmp("-Q", argv[1]))
    {
        return 5;
    }

    return -1;
}


void help()
{
    clear();
    printf("ALGORITHMS RESEARCH\n\n");
    printf("%sDESCRIPTION%s\n", BOLD, RESET);
    printf("\trun the program using at least one option for an algorithm. When the program\n\tfinishes, it will write to .csv file named by the algorithm.\n\n");
    printf("%sOPTIONS%s\n", BOLD, RESET);
    printf("\t-M %sMERGE SORT%s\n", BOLD, RESET);
    printf("\t\truns tests on Merge Sort Algorithm and writes results to 'results/merge.csv'.\n\n");
    printf("\t-H %sHEAP SORT%s\n", BOLD, RESET);
    printf("\t\truns tests on Heap Sort Algorithm and writes results to 'results/heap.csv'.\n\n");
    printf("\t-S %sSELECTION SORT%s\n", BOLD, RESET);
    printf("\t\truns tests on Selection Sort Algorithm and writes results to 'results/selection.csv'.\n\n");
    printf("\t-I %sINSERTION SORT%s\n", BOLD, RESET);
    printf("\t\truns tests on Insertion Sort Algorithm and writes results to 'results/insertion.csv'.\n\n");
    printf("\t-D %sDISTRIBUTION SORT%s\n", BOLD, RESET);
    printf("\t\truns tests on Distribution Sort Algorithm and writes results to 'results/distribution.csv'.\n\n");
    printf("\t-Q %sQUICK SORT%s\n", BOLD, RESET);
    printf("\t\truns tests on Quick Sort Algorithm and writes results to 'results/quick.csv'.\n\n");
}