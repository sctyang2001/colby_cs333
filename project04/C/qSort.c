/**
* qSort: Given an array of random integers, sort the array in a way that 
* the even numbers appear first and the odd numbers appear later.
*
* Scottie YANG Miaoyi
* Mar 11, 2021
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Function: comparator
 * --------------------
 * Returns where the element p and element q should be placed with respect to 
 * one another in the array to satisfy the sorting rules outlined above. 
 * 
 * Parameters:
 * const void *p: Left element pointer
 * const void *q: Right element pointer
 *
 * Returns: 
 * -1 if l goes first, 1 if r goes first. 
 */
int comparator (const void *p, const void *q) {

	// Get the values at the given element addresses 
    int l = *(const int *)p; 
    int r = *(const int *)q; 

    if ((l & 1) && (r & 1)) // If both are odd, put the lesser of two first. 
        return (l - r);
    
    if (!(l & 1) && !(r & 1)) // If both are even, put the greater of two first.
        return (r - l);
    
    if (!(l & 1)) // If only l is even, put l first.
        return -1;
    
    return 1; // If only l is odd, put r first.
}

int main (int argc, char **argv) {
	int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
	
	int size = sizeof(ary) / sizeof(int);
	
	qsort((void *) ary, size, sizeof(int), comparator);
	
	printf("The sorted array is: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	
	return 0;
}