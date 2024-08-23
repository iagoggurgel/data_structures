#include "utils.h"

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        exit(EXIT_FAILURE);
    }
    
    switch (checkOpt(argv))
    {
    case 0:
        testHeapSort();
        break;
    
    case 1:
        testMergeSort();
        break;

    case 2:
        testSelectionSort();
        break;

    case 3:
        testInsertionSort();
        break;

    case 4:
        // testDistributionSort();
        break;

    case 5:
        testQuickSort();
        break;

    case 6:
        testCountingSort();
        break;

    case 7:
        printf("%sSTARTING TO RUN COUNTING SORT!%s\n", BOLD, RESET);
        testCountingSort();
        printf("%sCOUNTING SORT RAN SUCCESSFULLY!%s\n", BOLD, RESET);

        printf("%sSTARTING TO RUN HEAP SORT!%s\n", BOLD, RESET);
        testHeapSort();
        printf("%sHEAP SORT RAN SUCCESSFULLY!%s\n", BOLD, RESET);

        printf("%sSTARTING TO RUN MERGE SORT!%s\n", BOLD, RESET);
        testMergeSort();
        printf("%sMERGE SORT RAN SUCCESSFULLY!%s\n", BOLD, RESET);

        printf("%sSTARTING TO RUN QUICK SORT!%s\n", BOLD, RESET);
        testQuickSort();
        printf("%sQUICK SORT RAN SUCCESSFULLY!%s\n", BOLD, RESET);

        printf("%sSTARTING TO RUN INSERTION SORT!%s\n", BOLD, RESET);
        testInsertionSort();
        printf("%sINSERTION SORT RAN SUCCESSFULLY!%s\n", BOLD, RESET);

        printf("%sSTARTING TO RUN SELECTION SORT!%s\n", BOLD, RESET);
        testSelectionSort();
        printf("%sSELECTION SORT RAN SUCCESSFULLY!%s\n", BOLD, RESET);

        break;

    default:
        help();
        exit(EXIT_FAILURE);
        break;
    }
    
    return EXIT_SUCCESS;
}