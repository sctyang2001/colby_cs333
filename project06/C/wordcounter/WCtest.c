/**
* WCtest.c: The program tests the WordCounter object.
* (This file is linked with "wordcounter.h" and "wordcounter.c".)
*
* Scottie YANG Miaoyi
* Apr 14, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "wordcounter.h"

int main(int argc, char *argv[]){
    WordCounter *wc;

    printf("This happens when main is called...\n");

	// create a WordCounter
	wc = wc_create();

	printf("This is after wc_create happens...\n");

    wc_read(wc, argv[1]);

    printf("This is after wc_read happens...\n");

    wc_print(wc);
}