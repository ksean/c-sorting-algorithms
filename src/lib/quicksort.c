#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;


Node *sortNodes(Node *start, Node *end) {

    Node first = *start;
    Node *firstSmaller;

    /* Are there >2 nodes in the list to sort? */
    if ( first.next ) {

        /* First node will be used at pivot, and we'll iterate the rest of the nodes with a cursor */
        Node cursor = *first.next;

        /* Create two new linked lists, one for values smaller than pivot, one for values larger than pivot */
        Node *firstLarger;

        /* We also remember the last node for easy insertion */
        Node *lastSmaller;
        Node *lastLarger;

        Node tmpNode = {cursor.value, &first};

        if ( first.value > cursor.value ) {
            *firstSmaller = tmpNode;
            *lastSmaller = tmpNode;
        } else {
            tmpNode.next = NULL;
            *firstLarger = tmpNode;
            *lastLarger = tmpNode;
        }

        /* Iterate all other elements in list until reach the end or NULL */
        while ( cursor.next && cursor.next != end ) {

            if ( first.value > cursor.value ) {
                *firstSmaller = tmpNode;
            } else {
                tmpNode.next = NULL;
                *firstLarger = tmpNode;
            }
        }

        first.next = firstLarger;

        sortNodes(firstSmaller, &first);
        sortNodes(firstLarger, NULL);
    }

    return firstSmaller;
}

void quicksort(int *input, int size)
{
	if ( size == 0 || size == 1 ) {
		return;
	}

	/*
	    It would be cumbersome to modify the input array in-place because a pivot would require rewriting multiple
	    elements in memory unnecessarily. Instead, we utilize aspects of a linked list structure which works well with
	    the quicksort algorithm, and then copy the sorted array over the input array upon completion.
	*/

	/* Convert to linked list of nodes */
	Node *cursor;
    printf("Converting to node");
	for ( int i = size - 1; i > -1; i-- ) {
	    Node node = { *(input + i), cursor };
	    *cursor = node;
	}

	/* Sort nodes */
	printf("Perform sort");
	cursor = sortNodes(cursor, NULL);

	/* Iteratively copy node values over input array */
	printf("Copy nodes into input array");
	for ( int j = 0; j < size; j++ ) {
	    Node cursorNode = *cursor;
	    input[j] = cursorNode.value;
	    cursor = cursorNode.next;
	}

	return;
}