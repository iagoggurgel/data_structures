#include "utils.h"

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