/**
* StackOverflow: This program checks if the system let the strcpy function overflow.
*
* Scottie YANG Miaoyi
* Feb 13, 2021
*
* TO RUN see example $ ./task05 (String), that you MUST put ONE string after 
* "./task05" to serve as a command-line argument. See example below:
* CORRECT Example: $ ./task05 PutaGuapa
* FALSE Example 1: $ ./task05 PutaGuapa Aloha
* FALSE Example 2: $ ./task05
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* We define one string of length 15, command line is to be copied into the length-15-array and we check if it overflows.
*/ 
int main (int argc, char *argv[]) {
    if (argc == 2) {
        char string2[15];
        int overflow = 0; 
        strcpy(string2, argv[1]);
        if (overflow == 0) {printf("%s\n", "safe");} else {printf("%s\n", "hacked");}
    }
    else if(argc < 2) {printf("One argument expected.\n");}
    else {printf("Too many arguments supplied.\n");}
}
