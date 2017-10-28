#include <stdio.h>
#include "bubblesort.h"

void printArrayContents(int *array, int size) 
{
    for ( int i = 0; i < size; i++ ) {
    	printf("%i ", array[i]);
    }
    printf("\n");
}

int main() 
{
	/* Basic example */
	int size = 10;
    int array[10] = {25, 20, 18, 16, 14, 10, 6, 5, 3, 2};

    printf("Before\n");
    printArrayContents(array, size);

    bubblesort(array, size);

    printf("After\n");
    printArrayContents(array, size);

    return 0;
}