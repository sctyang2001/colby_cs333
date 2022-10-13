/**
* floatingpointexception.c: The program demonstrates program-handled floating-point exceptions from arithmatic error.
*
* Scottie YANG Miaoyi
* Apr 14, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
  
// Handler for SIGFPE, caused by FPE.
void handle_sigfpe(int sig){
    printf("\nCaught floating-point exception.\n");
    signal(SIGINT, handle_sigfpe);
}

int main(){
    signal(SIGFPE, handle_sigfpe);
    int i=5/0;
    printf("Kept running...");
    return 0;
}