/**
* interrupt.c: The program demonstrates user-handled interrupt (ctrl-c) signal.
*
* Scottie YANG Miaoyi
* Apr 14, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
  
// Handler for SIGINT, caused by Ctrl-C on keyboard
void handle_sigint(int sig){
    printf("\nCaught Interrupt signal. Program interrupted.\n");
    exit(0);
}

int main(){
    // Infinite loop, break with keyboard interrupt
    signal(SIGINT, handle_sigint);
    while (1) ;
    return 0;
}