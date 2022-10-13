/**
* Memory Location: The program explores how memory is excessively allocated and freed in the memory.
*
* Scottie YANG Miaoyi
* Feb 13, 2021
*/

#include <stdio.h>
#include <stdlib.h>

/* Define a pointer and made it allocate the memory for a very long time non-stop.
* We are to compare if adding "free(c)" sentence will make a big difference in system memory.
*/ 
int main (int arg, char *argv[]) {
    int *c;
    for (int i=0; i<1000000000; i++){
        c = malloc(1000);
        free(c); // Free the memory of c.
    }
}
