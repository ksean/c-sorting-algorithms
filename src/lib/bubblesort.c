#include <stdio.h>
#include <stdbool.h>

void bubblesort(int *input, int size) 
{
	if ( size == 0 || size == 1 ) {
		return;
	}

	int i;
	int whileLoopCount = 0;
	bool swapPerformed = true;

	/* Loop until an iteration performs no swaps */
	while ( swapPerformed ) {

		swapPerformed = false;

		/* Traverse forwards along the array */
		for ( i = 0; i + whileLoopCount < size - 1; i++ ) {

			/* If the current element is greater than the next element, swap them */
			if ( *(input + i) > *(input + i + 1) ) {
				
				/* Perform swap */
				int temp = *(input + i);
				input[i] = *(input + i + 1); 
				input[i + 1] = temp;

				swapPerformed = true;
			}
		}

		/* 
			Each while loop iteration swaps the next highest element to the end of the array.
		    We don't need to check these end elements again in subsequent iterations.
		    This loop count is used to add a padding to the for loop. 
	    */
		whileLoopCount++;
	}
}