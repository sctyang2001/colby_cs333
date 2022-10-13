/**
* segfault.c: The program demonstrates user-handled segmentation fault.
*
* Scottie YANG Miaoyi
* Apr 14, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
  
// Handler for SIGSEGV, caused by a segmentation fault.
void handle_sigsegv(int sig){
    printf("\nCaught Segmentation Fault signal. Exiting...\n");
    exit(0);
}

int main()
{
    signal(SIGSEGV, handle_sigsegv);
    printf("Heading to create some undefined behavior...\n");
    *(char *)0 = 0;
    printf("If we got here, it means that the program continued after the seg fault occurred.\n");
    return 0;
}