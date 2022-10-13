/**
* Struct in Memory: The program explores how struct is stored in memory.
*
* Scottie YANG Miaoyi
* Feb 13, 2021
*/

#include <stdio.h>
#include <stdlib.h>

/* A struct that is called ID, now expected to have 5 bytes.
*/ 
typedef struct person {
char gender; //F or M
short byear;
short weight;
} ID;

/* We use the struct and input some data, then cast it to char pointer and output its structure in memory.
*/ 
int main (int arg, char *argv[]) {
    ID* Yang = (ID *) malloc (sizeof(ID)); // allocate space for struct ID.
    Yang->gender = 'M';
    Yang->byear = 2001;
    Yang->weight = 158;
    unsigned char *ptr_yang = (unsigned char *)(Yang); // We do not need a '&' before variable "Yang" because just like a string a var_name for a struct is referenced by an address itself.
    for(int i=0; i<sizeof(ID); i++) {
	    printf("Yang(ID) %d: %02X\n", i, ptr_yang[i]);
	}
}
