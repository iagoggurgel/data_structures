#include "utils.h"

<<<<<<< HEAD
int main(int argc, char * argv[])
{

    const int testCases = 10000;
    void * sortingAlgorithm;
    if (argc != 2)
    {
        exit(EXIT_FAILURE);
    }
    
    switch (checkOpt(argc, argv))
    {
    case 0:
        sortingAlgorithm = &hSort;
        break;
    
    case 1:
        sortingAlgorithm = &mSort;
        break;

    case 2:
        sortingAlgorithm = &sSort;
        break;

    case 3:
        sortingAlgorithm = &iSort;
        break;

    case 4:
        sortingAlgorithm = &dSort;
        break;

    case 5:
        sortingAlgorithm = &qSort;
        break;

    default:
        exit(EXIT_FAILURE);
    }

    int * inputArray = generateInput();
    
    
    return EXIT_SUCCESS;
}

int checkOpt(int argc, char * argv[])
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
}


=======
>>>>>>> 7bce2066329d43fd6ab19e28be89474302937fab
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

int main(int argc, char * argv[])
{
    void * sortingAlgorithm;
    
    return EXIT_SUCCESS;
}