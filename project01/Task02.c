/**
* Memory Location: The program explores how data is stored in the memory separately.
*
* Scottie YANG Miaoyi
* Feb 13, 2021
*/

#include <stdio.h>
#include <stdlib.h>

/* define and assign some types, then defind and cast an unsigned char to its own address.
*/ 
int main (int arg, char *argv[]) {
    char c = 'a';
    short sh = 5600;
    int i = 980000;
    long l = 6900000001;
    unsigned char *ptr = (unsigned char *)&(ptr);
	for(int i=0; i<150; i++) {
	    printf("current: %d - %02X\n", i, ptr[i]);
	}
}
