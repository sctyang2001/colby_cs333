/**
* cstk.h: The program contain the necessary sturctures and 
* the declarations of the basic functions of a stack.
* (This file is linked with "cstk.c".)
*
* Scottie YANG Miaoyi
* Mar 4, 2022
*/

#ifndef cstk
#define cstk

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int CSTK_MAX;

typedef struct Stack {
    int *stack;
    int top;
} Stack;

// Required by task.
Stack *stk_create(int size); 
void stk_push(Stack *S, int n); 
int stk_pop(Stack *S); 
void stk_display(Stack *S, int n); 
void stk_destroy(Stack *S); 

#endif /* cstk */